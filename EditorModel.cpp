// EditorModel.cpp
//
// ICS 45C Fall 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"
#include <string>


EditorModel::EditorModel()
    :   cursor_line{1}, 
        cursor_col{1}, 
        errorMessage{""}, 
        text_vector{""}
{
}


int EditorModel::cursorLine() const
{
    return cursor_line;
}


int EditorModel::cursorColumn() const
{
    return cursor_col;
}


int EditorModel::lineCount() const
{
    return text_vector.size();
}


const std::string& EditorModel::line(int lineNumber) const
{
    return text_vector.at(lineNumber-1);
}


const std::string& EditorModel::currentErrorMessage() const
{
    return errorMessage;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    this->errorMessage = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    this->errorMessage = "";
}


void EditorModel::move_right()
{
    if (cursor_line == lineCount() && cursor_col == line(lineCount()).size()+1)
    {
       throw EditorException("Already at end");
    }
    else if (cursor_col == line(cursor_line).size()+1)
    {
        cursor_line += 1;
        cursor_col = 1;
    }
    else
    {
        cursor_col += 1;
    }
    
}


void EditorModel::move_left()
{
    if (cursor_line == 1 && cursor_col == 1)
    {
        throw EditorException("Already at beginning");
    }
    else if (cursor_col == 1)
    {
        cursor_line -= 1;
        cursor_col = text_vector.at(cursor_line-1).size()+1;
    }
    else
    {
        cursor_col -= 1;   
    }    
}


void EditorModel::move_down()
{
    if (cursor_line == lineCount())
    {
        throw EditorException("Already at bottom");
    }
    else
    {
        if (cursor_col > (line(cursor_line+1).size()+1))
        {
            cursor_col = line(cursor_line+1).size()+1;
        }
        cursor_line += 1;
    }
    
}


void EditorModel::move_up()
{
    if (cursor_line == 1)
    {
        throw EditorException("Already at top");
    }
    else
    {
        if (cursor_col > (line(cursor_line-1).size()+1))
        {
            cursor_col = line(cursor_line-1).size()+1;
        }
        cursor_line -= 1;
    }
}


void EditorModel::insert_char(char c)
{
    text_vector.at(cursor_line-1).insert(cursor_col-1, 1, c);
    cursor_col += 1;
}


void EditorModel::new_line()
{
    if (cursor_col == line(cursor_line).size()+1 )    // if col == end of line
    {
        text_vector.insert(text_vector.begin()+cursor_line, "");
    }
    else
    {
        std::string str_after_cursor = line(cursor_line).substr(cursor_col-1);
        text_vector.insert(text_vector.begin() + cursor_line, str_after_cursor);

        text_vector.at(cursor_line-1).erase(line(cursor_line).begin() + (cursor_col-1), line(cursor_line).end());
    }
    cursor_line += 1;
    cursor_col = 1;
}


std::string EditorModel::delete_line()
{
    if (text_vector.size() == 1)
    {
        if (line(cursor_line) == "")
        {
            throw EditorException("Already empty");
        }
        else
        {
            std::string str_deleted = line(cursor_line);
            text_vector.at(0) = "";
            cursor_col = 1;
            return str_deleted;
        }
    
    }
    else if (cursor_line == text_vector.size())
    {
        // text_vector.erase(text_vector.begin()+text_vector.size());
        std::string str_deleted = line(cursor_line);
        text_vector.pop_back();
        move_up();        
        return str_deleted;
    }
    else
    {
        std::string str_deleted = line(cursor_line);   
        if (cursor_col > (line(cursor_line + 1).size() + 1) )
        {
            cursor_col = line(cursor_line).size() + 1;
        }
        text_vector.erase(text_vector.begin() + cursor_line - 1);
        
        return str_deleted;
    }   
}


void EditorModel::insert_line(std::string whole_ass_line, unsigned int line_num,
                              unsigned int prev_col, unsigned int prev_size)
{

    if (line_num == 1 && prev_size == 1)
    {
        text_vector.at(0) = whole_ass_line;
        cursor_col = prev_col;
    }
    else if (line_num - 1 >= text_vector.size())
    {
        text_vector.push_back(whole_ass_line);
        cursor_line = line_num;
        cursor_col = prev_col;
    }
    else
    {
        cursor_line = line_num;
        cursor_col = prev_col;
        text_vector.insert(text_vector.begin()+line_num-1, whole_ass_line);   
    }
}


char EditorModel::backspace()
{
    if (cursor_col == 1)
    {
        if (cursor_line == 1)
        {
            throw EditorException("Already at beginning");
        }
        else
        {
            std::string string_in_front_of_cursor = line(cursor_line);
            cursor_col = line(cursor_line-1).size() + 1;
            text_vector.at(cursor_line-2).append(string_in_front_of_cursor);    // above the line to the end
                                                                                // to the line above
            
            text_vector.erase(text_vector.begin()+cursor_line-1);     // kill the prev line
            
            cursor_line -= 1;

            return '\0';
        }
        
       
    }
    else
    {
        char char_behind_cursor = text_vector.at(cursor_line-1).at(cursor_col-2);
        text_vector.at(cursor_line-1).erase(cursor_col-2,1);
        cursor_col -=1;
        return char_behind_cursor;
    }   
}


unsigned int EditorModel::cursor_home()
{
    unsigned int orig_col = cursor_col;
    cursor_col = 1;
    return orig_col;
}


unsigned int EditorModel::cursor_end()
{
    unsigned int orig_col = cursor_col;
    cursor_col = text_vector.at(cursor_line-1).size()+1;
    return orig_col;
}


void EditorModel::set_col(unsigned int col)
{
    cursor_col = col;
}