// UpCmd.cpp

#include "UpCmd.hpp"

void UpCmd::execute(EditorModel& model)
{
    prev_col = model.cursorColumn();
    model.move_up();   
}

void UpCmd::undo(EditorModel& model)
{
    model.move_down();
    model.set_col(prev_col);
}