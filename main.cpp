//
// Created by caidend on 6/29/2026.
//

#include "Deck.h"
#include <iostream>

#include "Blackjack_controller.h"
namespace {
    constexpr const char* clear_screen = "\x1b[2J\x1b[H";
}


int main() {
    while (true) {
        Blackjack_controller blackjack;
        blackjack.game_setup_reset();
        blackjack.initial_deal();
        blackjack.player_turn();
        blackjack.dealer_turn();
        blackjack.determine_result();
        std::cout << clear_screen;
        blackjack.determine_result();
    }
    return 0;
}
