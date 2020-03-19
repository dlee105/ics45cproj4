// DeleteLineCmd.cpp

#include "DeleteLineCmd.hpp"

void DeleteLineCmd::execute(EditorModel& model)
{
    line_num = model.cursorLine();
    prev_col = model.cursorColumn();
    prev_size = model.lineCount();
    deleted_line = model.delete_line();
}


void DeleteLineCmd::undo(EditorModel& model)
{
    model.insert_line(deleted_line, line_num, prev_col, prev_size);
}