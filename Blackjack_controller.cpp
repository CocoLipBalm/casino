//
// Created by caidend on 6/30/2026.
//

#include "Blackjack_controller.h"

#include <iostream>

namespace {
constexpr const char* clear_screen = "\x1b[2J\x1b[H";
}

Blackjack_controller::Blackjack_controller() = default;

void Blackjack_controller::game_setup_reset() {
    deck.rebuildAndShuffle();
    player_hand.clear_hand();
    dealer_hand.clear_hand();
    burn_hand.clear_hand();
}

void Blackjack_controller::initial_deal() {
    burn_hand.deal_hand(deck, 1);
    dealer_hand.deal_hand(deck, 1);
    player_hand.deal_hand(deck, 1);
    dealer_hand.deal_hand(deck, 1);
    player_hand.deal_hand(deck, 1);
}

void Blackjack_controller::display_table(const bool hide_dealer_hole_card) const {
    std::cout << "Your cards:\n";
    player_hand.display_hand();
    std::cout << "\nTotal: " << player_hand.get_BJ_value() << "\n\n";

    std::cout << "Dealer cards:\n";
    dealer_hand.display_hand(hide_dealer_hole_card);
    std::cout << "\nTotal: " << dealer_hand.get_BJ_value(hide_dealer_hole_card) << "\n";
}

void Blackjack_controller::player_turn() {
    display_table(true);

    while (player_hand.get_BJ_value() < 21) {
        std::cout << "\nWhat is your choice? Hit (q) or stand (w): ";

        char choice {};
        do {
            std::cin >> choice;
        } while (choice != 'q' && choice != 'w');

        if (choice == 'w') {
            break;
        }

        player_hand.deal_hand(deck, 1);
        std::cout << clear_screen;
        display_table(true);
    }
}

void Blackjack_controller::dealer_turn() {
    if (player_hand.get_BJ_value() > 21) {
        return;
    }

    while (dealer_hand.get_BJ_value() < 17) {
        dealer_hand.deal_hand(deck, 1);
    }
}

void Blackjack_controller::determine_result() const {
    const int dealer_hand_value = dealer_hand.get_BJ_value();
    const int player_hand_value = player_hand.get_BJ_value();

    std::cout << clear_screen;
    display_table(false);

    if (player_hand_value > 21) {
        std::cout << "\x1b[91mYou lose\n\x1b[0m";
    } else if (dealer_hand_value > 21 || player_hand_value > dealer_hand_value) {
        std::cout << "\x1b[92mYou win\n\x1b[0m";
    } else if (player_hand_value < dealer_hand_value) {
        std::cout << "\x1b[91mYou lose\n\x1b[0m";
    } else {
        std::cout << "\x1b[93mPush\n\x1b[0m";
    }
}
