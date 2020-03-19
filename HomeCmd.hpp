// HomeCmd.hpp

#ifndef HOMECMD_HPP
#define HOMECMD_HPP

#include "Command.hpp"

class HomeCmd : public Command
{
public:
    HomeCmd();

    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    unsigned int prev_col;
};

#endif