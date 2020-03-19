// DownCmd.hpp

#ifndef DOWNCMD_HPP
#define DOWNCMD_HPP

#include "Command.hpp"

class DownCmd : public Command
{
public:
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    unsigned int prev_col;
};

#endif