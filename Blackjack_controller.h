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

    void game_setup_reset();
    void initial_deal();
    void player_turn();
    void dealer_turn();
    void determine_result() const;
    //display outcome

private:
    Deck deck;
    Hand player_hand;
    Hand dealer_hand;
    Hand burn_hand;
};


#endif //CASINO_BLACKJACK_CONTROLLER_H
