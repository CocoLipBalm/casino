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
    dealer_hand.deal_hand(deck, 1);//TODO: make this card hidden
    player_hand.deal_hand(deck, 1);
}

void Blackjack_controller::player_turn() {
    int player_val = player_hand.get_BJ_value();
    int dealer_val = dealer_hand.get_BJ_value();

    std::cout << "Your cards: \n";
    player_hand.display_hand();
    std::cout << "Total: " << player_hand.get_BJ_value() <<'\n';
    std::cout << '\n';

    std::cout << "Dealer Card: \n";
    dealer_hand.display_hand(true);
    std::cout << "Total: " << dealer_hand.get_BJ_value(true) <<'\n';
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
            std::cout << "Total: " << dealer_hand.get_BJ_value(true) <<'\n';
        } else if (choice == 'w') {
            break;
        }
    }
}

void Blackjack_controller::dealer_turn() {
    while (dealer_hand.get_BJ_value() < 17) {

        dealer_hand.deal_hand(deck, 1);
        dealer_hand.display_hand();
        std::cout << "Total: " << dealer_hand.get_BJ_value() << '\n';
    }
}

void Blackjack_controller::determine_result() const {
    const int dealer_hand_value = dealer_hand.get_BJ_value();
    const int player_hand_value = player_hand.get_BJ_value();
    std::cout << "\x1b[2J\x1b[H";
    std::cout << "Dealer Cards are:\n";
    dealer_hand.display_hand();
    std::cout << "Total: " << dealer_hand_value <<'\n';
    std::cout << "Player Cards are:\n";
    player_hand.display_hand();
    std::cout << "Total: " << player_hand_value <<'\n';

    if (player_hand_value > 21) {
        std::cout << "\x1b[91m" << "You lose\n" << "\x1b[0m";
    } else if (dealer_hand_value > 21) {
        std::cout << "\x1b[92m"<< "You win\n" << "\x1b[0m";
    } else if (player_hand_value > dealer_hand_value) {
        std::cout << "\x1b[92m"<< "You win\n" << "\x1b[0m";
    } else if (player_hand_value < dealer_hand_value) {
        std::cout << "\x1b[91m" << "You lose\n" << "\x1b[0m";
    } else {
        std::cout <<"\x1b[93m" << "Push\n" << "\x1b[0m";
    }
}