// HomeCmd.cpp

#include "HomeCmd.hpp"

HomeCmd::HomeCmd()
    : prev_col{0}
{
}


void HomeCmd::execute(EditorModel& model)
{
    prev_col = model.cursor_home();
}


void HomeCmd::undo(EditorModel& model)
{
    model.set_col(prev_col);
}