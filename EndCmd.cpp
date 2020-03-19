// EndCmd.cpp

#include "EndCmd.hpp"

EndCmd::EndCmd()
    : prev_col{0}
{
}


void EndCmd::execute(EditorModel& model)
{
    prev_col = model.cursor_end();
}


void EndCmd::undo(EditorModel& model)
{
    model.set_col(prev_col);
}