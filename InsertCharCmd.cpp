// InsertCharCmd.cpp

#include "InsertCharCmd.hpp"

InsertCharCmd::InsertCharCmd(char character)
    : c{character}
{
}

void InsertCharCmd::execute(EditorModel& model)
{
    model.insert_char(c);
}


void InsertCharCmd::undo(EditorModel& model)
{
    model.backspace();
}