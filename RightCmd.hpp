// RightCmd.hpp

#ifndef RIGHTCMD_HPP
#define RIGHTCMD_HPP

#include "Command.hpp"

class RightCmd : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;
};

#endif