// LeftCmd.cpp
#include "LeftCmd.hpp"


void LeftCmd::execute(EditorModel& model)
{
    model.move_left();
}


void LeftCmd::undo(EditorModel& model)
{
    model.move_right();
}