// UpCmd.hpp

#ifndef UPCMD_HPP
#define UPCMD_HPP

#include "Command.hpp"

class UpCmd : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    unsigned int prev_col;
};

#endif