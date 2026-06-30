//
// Created by caidend on 6/30/2026.
//

#ifndef CASINO_BLACKJACK_CONTROLLER_H
#define CASINO_BLACKJACK_CONTROLLER_H

#include <Deck.h>

#include "Hand.h"

class Blackjack_controller {
public:
    Blackjack_controller();

    //void setup_reset
    //void initialdeal
    //void player turn
    //dealer turn
    //determine result
    //display outcome

private:
    Deck deck;
    Hand player_hand;
    Hand dealer_hand;
};


#endif //CASINO_BLACKJACK_CONTROLLER_H
