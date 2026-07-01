//
// Created by caide on 6/29/2026.
//

#include "Hand.h"
#include "Deck.h"

#include <iostream>
#include <unordered_map>

Hand::Hand() = default;

void Hand::deal_hand(Deck& deck, const int amount) {
    for (int i = 0; i < amount; ++i) {
        if (const auto new_card = deck.deal()) {
            hand.push_back(*new_card);
        } else {
            std::cerr << "Cannot deal: the deck is empty.\n";
            return;
        }
    }
}

size_t Hand::size_count_hand() const {
    return hand.size();
}

void Hand::display_hand(const bool hide_hole_card) const {
    for (size_t i = 0; i < hand.size(); ++i) {
        if (i == 1 && hide_hole_card) {
            std::cout << " \x1b[31m(?, ?)\x1b[0m";
            break;
        }

        if (i != 0) {
            std::cout << ' ';
        }

        std::cout << hand[i].to_string();
    }
}

void Hand::clear_hand() {
    hand.clear();
}

std::vector<Card> Hand::get_hand() const {
    return hand;
}

int Hand::get_BJ_value(const bool first_card_only) const {
    const std::unordered_map<Rank, int> rank_map {
                {Two, 2}, {Three, 3},
                {Four, 4}, {Five, 5},
                {Six, 6}, {Seven, 7},
                {Eight, 8}, {Nine, 9},
                {Ten, 10}, {Jack, 10},
                {Queen, 10}, {King, 10}, {Ace, 1}
    };

    int total = 0;
    int ace_count = 0;

    for (const Card& card : hand) {
        if (first_card_only) {
            return card.get_rank() == Ace ? 11 : rank_map.at(card.get_rank());
        }

        if (card.get_rank() == Ace) {
            ++ace_count;
        }

        total += rank_map.at(card.get_rank());
    }

    if (ace_count > 0 && total + 10 <= 21) {
        total += 10;
    }

    return total;
}
