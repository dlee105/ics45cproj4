// RightCmd.cpp
#include "RightCmd.hpp"


void RightCmd::execute(EditorModel& model)
{
    model.move_right();
}


void RightCmd::undo(EditorModel& model)
{
    model.move_left();
}