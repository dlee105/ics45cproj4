// NewLineCmd.cpp

#include "NewLineCmd.hpp"

void NewLineCmd::execute(EditorModel& model)
{
    model.new_line();
}


void NewLineCmd::undo(EditorModel& model)
{
    model.backspace();
}