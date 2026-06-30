//
// Created by caidend on 6/30/2026.
//

#include "Blackjack_controller.h"
#include "iostream"
#include <unordered_map>

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
    int pval = player_hand.get_BJ_value();
    int dval = dealer_hand.get_BJ_value();
    std::cout << "Its your turn you have cards:\n";
    player_hand.display_hand();
    std::cout << "Total: " << pval <<'\n';
    std::cout << '\n';
    std::cout << "Dealer Cards are:\n";
    dealer_hand.display_hand();
    std::cout << "Total: " << dval <<'\n';
    std::cout << "What is your choice, to hit (q), to stand (w)\n"; //implement double down and split

    char choice;
    while (player_hand.get_BJ_value() < 21) {
        do std::cin >> choice; while (choice != 'q' && choice != 'w');
        if (choice == 'q') {
            player_hand.deal_hand(deck, 1);
            std::cout << "Player Cards are:\n";
            dealer_hand.display_hand();
            const int new_pval = player_hand.get_BJ_value();
            std::cout << "Total: " << new_pval <<'\n';
            std::cout << '\n';
            std::cout << "Dealer Cards are:\n";
            player_hand.display_hand();
            std::cout << "Total: " << dval <<'\n';
        } else if (choice == 'w') {
            break;
        }
    }
}

void Blackjack_controller::dealer_turn() {
    while (dealer_hand.get_BJ_value() < 17) {
        dealer_hand.deal_hand(deck, 1);
        dealer_hand.display_hand();
    }
}

void Blackjack_controller::determine_result() const {
    const int dealer_hand_value = dealer_hand.get_BJ_value();
    const int player_hand_value = player_hand.get_BJ_value();
    std::cout << "Dealer Cards are:\n";
    dealer_hand.display_hand();
    std::cout << "Total: " << dealer_hand_value <<'\n';
    std::cout << "Player Cards are:\n";
    player_hand.display_hand();
    std::cout << "Total: " << player_hand_value <<'\n';

    if (player_hand_value > 21) {
        std::cout << "You lose\n";
    } else if (dealer_hand_value > 21) {
        std::cout << "You win\n";
    } else if (player_hand_value > dealer_hand_value) {
        std::cout << "You win\n";
    } else if (player_hand_value < dealer_hand_value) {
        std::cout << "You lose\n";
    } else {
        std::cout << "Push\n";
    }
}