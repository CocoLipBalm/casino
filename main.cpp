//
// Created by caidend on 6/29/2026.
//

#include "Deck.h"
#include <iostream>

#include "Blackjack_controller.h"


int main() {
    Blackjack_controller blackjack;
    blackjack.game_setup_reset();
    blackjack.initial_deal();
    blackjack.player_turn();
    blackjack.determine_result();

    return 0;
}
