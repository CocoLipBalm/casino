//
// Created by caidend on 6/30/2026.
//

#include "Blackjack_controller.h"
#include "iostream"

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

void Blackjack_controller::player_turn() {
    std::cout << "Its your turn you have cards:\n";
    player_hand.display_hand();
    std::cout << '\n';
    std::cout << "What is your choice, to hit (q), to stand (w)\n"; //implement double down and split

    char choice;
    std::cin >> choice;
    while (player_hand.value_count_hand() < 21) {
        do std::cin >> choice; while (choice != 'q' && choice != 'w');
        if (choice == 'q') {
            player_hand.deal_hand(deck, 1);
        }
    }
}

void Blackjack_controller::dealer_turn() {
    while (dealer_hand.value_count_hand() < 16) {
        dealer_hand.deal_hand(deck, 1);
        dealer_hand.display_hand();
    }
}

void Blackjack_controller::determine_result() const {
    const int dealer_hand_value = dealer_hand.value_count_hand();
    const int player_hand_value = player_hand.value_count_hand();
    std::cout << "Dealer Cards are:\n";
    dealer_hand.display_hand();
    std::cout << "Total: " << dealer_hand_value <<'\n';
    std::cout << "Player Cards are:\n";
    player_hand.display_hand();
    std::cout << "Total: " << player_hand_value <<'\n';
    if (player_hand_value <= 21 && dealer_hand_value <= 21) {
        if (dealer_hand_value == player_hand_value) {
            std::cout << "Push";
        } else if (player_hand_value > dealer_hand_value) {
            std::cout << "You win";
        } else if (player_hand_value < dealer_hand_value) {
            std::cout << "You lose";
        }
    } else {
        std::cout << "You lose";
    }
}