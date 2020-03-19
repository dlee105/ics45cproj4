// LeftCmd.hpp

#ifndef LEFTCMD_HPP
#define LEFTCMD_HPP

#include "Command.hpp"

class LeftCmd : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif