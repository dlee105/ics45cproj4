// KeypressInteractionReader.cpp
//
// ICS 45C Fall 2019
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "RightCmd.hpp"
#include "LeftCmd.hpp"
#include "DownCmd.hpp"
#include "UpCmd.hpp"
#include "InsertCharCmd.hpp"
#include "BackspaceCmd.hpp"
#include "HomeCmd.hpp"
#include "EndCmd.hpp"
#include "NewLineCmd.hpp"
#include "DeleteLineCmd.hpp"


// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
                
                case 'O':
                {
                    return Interaction::command(new RightCmd);
                }
                case 'U':
                {
                    return Interaction::command(new LeftCmd);
                }
                case 'K':
                {
                    return Interaction::command(new DownCmd);
                }
                case 'I':
                {
                    return Interaction::command(new UpCmd);
                }
                case 'Y':
                {
                    return Interaction::command(new HomeCmd);
                }
                case 'P':
                {
                    return Interaction::command(new EndCmd);
                }
                case 'J':
                {
                    return Interaction::command(new NewLineCmd);
                }
                case 'D':
                {
                    return Interaction::command(new DeleteLineCmd);
                }
                case 'M':
                {
                    return Interaction::command(new NewLineCmd);
                }
                case 'H':
                {
                    return Interaction::command(new BackspaceCmd);
                }
                case 'Z':
                {
                    return Interaction::undo();
                }
                case 'A':
                {
                    return Interaction::redo();
                }
                case 'X':
                {
                    return Interaction::quit();
                }                
            }
        }
        else
        {
            return Interaction::command(new InsertCharCmd(keypress.code()));
        }
    }
}

