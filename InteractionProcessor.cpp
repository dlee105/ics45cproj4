// InteractionProcessor.cpp
//
// ICS 45C Fall 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();

    std::vector<Command*> undoVector;
    std::vector<Command*> redoVector;

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (undoVector.size() > 0)
            {
                Command* command = undoVector.back();
                command->undo(model); 
                model.clearErrorMessage();
                redoVector.push_back(command);
                undoVector.pop_back();
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if (redoVector.size() > 0)
            {
                Command* command = redoVector.back();
                command->execute(model);
                model.clearErrorMessage();
                undoVector.push_back(command);
                redoVector.pop_back();
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();
            undoVector.push_back(command);
            
            try
            {
                command->execute(model);
                model.clearErrorMessage();
                while (redoVector.empty() == false)
                {
                    delete redoVector.back();
                    redoVector.pop_back();
                }
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
                delete command;
                undoVector.pop_back();
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore
            
            // CHANGE THIS TO DELETE EVERY CMD IN THE REDO VECTOR ONCE YOU IMPLEMENT
            // "REDO" AND "UNDO" BRANCHES AND MAKE VECTORS FOR THOSE BRANCHES

        }
    }
    while (redoVector.empty() == false)
            {
                delete redoVector.back();
                redoVector.pop_back();
            }
    while (undoVector.empty() == false)
            {
                delete undoVector.back();
                undoVector.pop_back();
            }

}

