// DeleteLineCmd.hpp

#ifndef DELETELINECMD_HPP
#define DELETELINECMD_HPP

#include "Command.hpp"

class DeleteLineCmd : public Command
{
public:
    void execute(EditorModel& model);
    void undo(EditorModel& model);

private:
    std::string deleted_line;
    unsigned int line_num;
    unsigned int prev_col;
    unsigned int prev_size;
};
#endif