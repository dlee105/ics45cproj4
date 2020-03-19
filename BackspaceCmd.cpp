// BackspaceCmd.cpp

#include "BackspaceCmd.hpp"


void BackspaceCmd::execute(EditorModel& model)
{
    prev_col = model.cursorColumn();
    deleted_char = model.backspace();
}


void BackspaceCmd::undo(EditorModel& model)
{
    if (prev_col == 1)
    {
        model.new_line();
    }
    else
    {
        model.insert_char(deleted_char);
    }
}