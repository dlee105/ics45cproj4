// EndCmd.hpp

#ifndef ENDCMD_HPP
#define ENDCMD_HPP

#include "Command.hpp"

class EndCmd : public Command
{
public:
    EndCmd();

    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    unsigned int prev_col;
};

#endif