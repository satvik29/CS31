//
//  Player.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"
#include <iostream>

namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mRound( 0 )
    {
        
    }
    
    // TODO: roll the die and adjust the score for the current round
    // accordingly
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    int Player::roll( int amount )
    {
        int amountRolled = 0;
//        amount = 4;
        if (amount != 0) {
            amountRolled = amount;
        }
        
        if (amount == 0) {
            mDie.roll();
            amountRolled = mDie.getValue();
        }
        
        if (amountRolled == mRound) {
            mScore++;
        }
        
        return amountRolled;
    }
    
    // TODO: set the current round and reset the player's score to 0
    void Player::setRound( int round )
    {
        mRound = round;
        mScore = 0;
    }
    
    // TODO: return the score member variable
    int  Player::getScore( ) const
    {
        return mScore;
    }
}
