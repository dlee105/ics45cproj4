// InsertCharCmd.hpp

#ifndef INSERTCHAR_CMD
#define INSERTCHAR_CMD

#include "Command.hpp"

class InsertCharCmd : public Command
{
public:
    InsertCharCmd(char character);
    void execute(EditorModel& model) override;
    void undo(EditorModel& model) override;

private:
    char c;
};

#endif