//
//  main.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include <iostream>
#include "Die.h"
#include "Player.h"
#include "Bunco.h"
#include <cassert>


void clearScreen( );

int main()
{
    using namespace std;
    using namespace cs31;
    
    // test code
    Die d;
    for (int i = 1; i <= 100; i++)
    {
        d.roll();
        int value = d.getValue();
        assert( value >=1 && value <= 6 );
    }
    
    
    Player p;
    assert( p.getScore() == 0 );
    p.setRound( 1 );
    assert( p.getScore() == 0 );
    assert( p.roll( 6 ) == 6 );
    assert( p.getScore() == 0 );
    assert( p.roll( 5 ) == 5 );
    assert( p.getScore() == 0 );
    assert( p.roll( 1 ) == 1);
    assert( p.getScore() == 1 );
    p.setRound( 6 );
    assert( p.getScore() == 0 );
    assert( p.roll( 6 ) == 6 );
    assert( p.getScore() == 1 );
    
    Player q;
    assert(q.getScore() == 0);
    q.setRound(4);
    assert(q.getScore() == 0);
    q.roll(4);
    assert(q.getScore() == 1);
    
    Bunco bi;
    bi.setRound( 1 );
    assert( bi.determineRoundOutcome() == Bunco::NOTDECIDED );
    bi.computerPlay( 5 );
    bi.humanPlay( 5 );
    assert( bi.determineRoundOutcome() == Bunco::NOTDECIDED );
    bi.computerPlay( 1 );
    bi.humanPlay( 1 );
    assert( bi.determineRoundOutcome() == Bunco::NOTDECIDED );
    bi.computerPlay( 1 );
    bi.humanPlay( 2 );
    assert( bi.determineRoundOutcome() == Bunco::COMPUTERWON );
    
    
    Player testPlayer;
    // To test whether the function roll returns what it should and to see whether getScore increments correctly
    assert(testPlayer.roll(5) == 5);
    assert(testPlayer.getScore() == 0);
    
    // To test whether the function setRound sets the round appropriately and whether getScore increments correctly
    testPlayer.setRound(3);
    testPlayer.roll(3);
    assert(testPlayer.getScore() == 1);
    
    
    Bunco trial;
    // To test whether ComputerPlay and humanPlay work appropriately
    assert(trial.computerPlay(4) == 4);
    assert(trial.humanPlay(3) == 3);
    
    // To test whether a trial round where the computer wins works correctly
    trial.setRound(1);
    trial.computerPlay(1);
    trial.humanPlay(2);
    assert(trial.computerPlay(1) == 1);
    assert(trial.humanPlay(2) == 2);
    // This assert tests all the functions of Board and BoardRow as well, along with checking whether determineRoundOutcome works appropriately
    assert(trial.determineRoundOutcome() == Bunco::COMPUTERWON);
    // To check whether determineGameOutcome works properly
    assert(trial.determineGameOutcome() == Bunco::GAMENOTOVER);
    
    trial.setRound(2);
    trial.computerPlay(2);
    trial.humanPlay(2);
    // To check whether when both the computer and human roll the same die, the game is still not decided
    assert(trial.determineRoundOutcome() == Bunco::NOTDECIDED);
    trial.computerPlay(2);
    trial.humanPlay(3);
    assert(trial.determineRoundOutcome() == Bunco::COMPUTERWON);
    
    trial.setRound(3);
    trial.computerPlay(3);
    trial.humanPlay(2);
    assert(trial.determineRoundOutcome() == Bunco::COMPUTERWON);
    
    trial.setRound(4);
    trial.computerPlay(4);
    trial.humanPlay(2);
    assert(trial.determineRoundOutcome() == Bunco::COMPUTERWON);
    
    trial.setRound(5);
    trial.computerPlay(3);
    trial.humanPlay(5);
    assert(trial.determineRoundOutcome() == Bunco::HUMANWON);
    
    trial.setRound(6);
    trial.computerPlay(3);
    trial.humanPlay(6);
    assert(trial.determineRoundOutcome() == Bunco::HUMANWON);
    
    // To check whether determineGameOutcome works appropriately
    assert(trial.determineGameOutcome() == Bunco::COMPUTERWONGAME);

    // To test whether a trial game in which the human wins works correctly
    Bunco trial1;
    
    trial1.setRound(1);
    trial1.computerPlay(2);
    trial1.humanPlay(1);
    assert(trial1.determineRoundOutcome() == Bunco::HUMANWON);
    
    trial1.setRound(2);
    trial1.computerPlay(2);
    trial1.humanPlay(2);
    assert(trial1.determineRoundOutcome() == Bunco::NOTDECIDED);
    trial1.computerPlay(3);
    trial1.humanPlay(2);
    assert(trial1.determineRoundOutcome() == Bunco::HUMANWON);
    
    trial1.setRound(3);
    trial1.computerPlay(4);
    trial1.humanPlay(3);
    assert(trial1.determineRoundOutcome() == Bunco::HUMANWON);
    
    trial1.setRound(4);
    trial1.computerPlay(2);
    trial1.humanPlay(4);
    assert(trial1.determineRoundOutcome() == Bunco::HUMANWON);
    
    trial1.setRound(5);
    trial1.computerPlay(3);
    trial1.humanPlay(5);
    assert(trial1.determineRoundOutcome() == Bunco::HUMANWON);
    
    trial1.setRound(6);
    trial1.computerPlay(2);
    trial1.humanPlay(6);
    assert(trial1.determineRoundOutcome() == Bunco::HUMANWON);
    
    assert(trial1.determineGameOutcome() == Bunco::HUMANWONGAME);
    
    // To check whether a game in which the computer and the human tie works correctly

    Bunco trial2;
    
    trial2.setRound(1);
    trial2.computerPlay(1);
    trial2.humanPlay(2);
    assert(trial2.determineRoundOutcome() == Bunco::COMPUTERWON);
    
    trial2.setRound(2);
    trial2.computerPlay(3);
    trial2.humanPlay(2);
    assert(trial2.determineRoundOutcome() == Bunco::HUMANWON);
    
    trial2.setRound(3);
    trial2.computerPlay(3);
    trial2.humanPlay(4);
    assert(trial2.determineRoundOutcome() == Bunco::COMPUTERWON);
    
    trial2.setRound(4);
    trial2.computerPlay(2);
    trial2.humanPlay(4);
    assert(trial2.determineRoundOutcome() == Bunco::HUMANWON);
    
    trial2.setRound(5);
    trial2.computerPlay(5);
    trial2.humanPlay(3);
    assert(trial2.determineRoundOutcome() == Bunco::COMPUTERWON);
    
    trial2.setRound(6);
    trial2.computerPlay(2);
    trial2.humanPlay(6);
    assert(trial2.determineRoundOutcome() == Bunco::HUMANWON);
    
    assert(trial2.determineGameOutcome() == Bunco::TIEDGAME);
    

 
    cout << "all tests passed!" << endl;
    return 0;
 
}


/*
int main()
{
 
    using namespace cs31;
    using namespace std;
 
    clearScreen();
 
    Bunco game;
    int human, computer;
    int round = 1;
    game.setRound( round );
    std::string action, message = "(r)oll (q)uit: ";
    cout << game.display( message ) << endl;

    
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'r':
            case 'R':
                human = game.humanPlay();
                computer = game.computerPlay();
                cout << "human rolled:" << human;
                cout << "\tcomputer rolled:" << computer << endl;

                if (game.determineRoundOutcome() != Bunco::NOTDECIDED)
                {
                    round = round + 1;
                    game.setRound(round);
                    cout << game.display( message ) << endl;
                }
                if (game.gameIsOver())
                {
                    cout << game.display( ) << endl;
                }
                break;
        }
        
    } while( !game.gameIsOver() );
    
    return( 0 );
}

*/

void clearScreen();



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

