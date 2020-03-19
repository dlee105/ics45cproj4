// DownCmd.cpp

#include "DownCmd.hpp"

void DownCmd::execute(EditorModel& model)
{
    prev_col = model.cursorColumn();
    model.move_down();
}

void DownCmd::undo(EditorModel& model)
{
    model.move_up();
    model.set_col(prev_col);
}