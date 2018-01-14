//
//  Bunco.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Bunco.h"
#include "Player.h"
#include "Die.h"
#include "Board.h"
#include "BoardRow.h"
#include <iostream>
#include <cassert>

namespace cs31
{
    Bunco::Bunco() : mRound( 0 )
    {
        
    }
    
    // stringify the game by stringifying the board
    std::string Bunco::display( std::string msg ) const
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        
        if (gameIsOver())
        {
            if (determineGameOutcome() == TIEDGAME)
            {
                s = s + "\n\t\tBunco wound up tied!\n";
            }
            else if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Bunco!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Bunco!\n";
            }
        }
        return( s );
    }
    
    // set the current round of play, notifying the board and each
    // player of the current round
    void Bunco::setRound( int round )
    {
        mRound = round;
        mBoard.setCurrentRound( round );
        mHuman.setRound(round);
        mComputer.setRound(round);
    }
    
    // TODO: let the human player play
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    int Bunco::humanPlay( int amount )
    {
        int humanRoll = 0;
        
        humanRoll = mHuman.roll(amount);

        return humanRoll;
    }
    
    // TODO: let the computer player play
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    int Bunco::computerPlay( int amount )
    {
        int computerRoll = 0;
        
        computerRoll = mComputer.roll(amount);
        
        return computerRoll;
    }
    
    // TODO: considering each player's score, determine the
    // winner of this round of play
    Bunco::ROUNDOUTCOME Bunco::determineRoundOutcome()
    {
        ROUNDOUTCOME result = ROUNDOUTCOME::NOTDECIDED;
        
        if (mHuman.getScore() > mComputer.getScore()) {
            mBoard.markHumanAsWinner();
            result = ROUNDOUTCOME::HUMANWON;
        }
        
        if (mHuman.getScore() < mComputer.getScore()) {
            mBoard.markComputerAsWinner();
            result = ROUNDOUTCOME::COMPUTERWON;
        }
 
        return( result );
    }
    
    // TODO: count up the number of won rounds by each player to determine
    // the game's outcome
    Bunco::GAMEOUTCOME  Bunco::determineGameOutcome( ) const
    {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
        
        if (mBoard.countUpComputerRoundWins() + mBoard.countUpHumanRoundWins() == 6) {
            if (mBoard.countUpComputerRoundWins() > mBoard.countUpHumanRoundWins()) {
                result = GAMEOUTCOME::COMPUTERWONGAME;
            }
                
            if (mBoard.countUpHumanRoundWins() > mBoard.countUpComputerRoundWins()) {
                result = GAMEOUTCOME::HUMANWONGAME;
            }
                
            if (mBoard.countUpComputerRoundWins() == mBoard.countUpHumanRoundWins()) {
                result = GAMEOUTCOME::TIEDGAME;
            }
        }
        
        return( result );
    }
    
    // is the game over?
    bool Bunco::gameIsOver() const
    {
        GAMEOUTCOME result = determineGameOutcome();
        return( result != GAMENOTOVER );
    }

}


