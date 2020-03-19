// BackspaceCmd.hpp

#ifndef BACKSPACECMD_HPP
#define BACKSPACECMD_HPP

#include "Command.hpp"

class BackspaceCmd : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    char deleted_char;
    unsigned int prev_col;
};

#endif