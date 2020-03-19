// NewLineCmd.hpp

#ifndef NEWLINECMD_HPP
#define NEWLINECMD_HPP

#include "Command.hpp"

class NewLineCmd : public Command
{
public:
    void execute(EditorModel& model);
    void undo(EditorModel& model);
};

#endif