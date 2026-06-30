//
// Created by caide on 6/29/2026.
//
#include "Deck.h"
#include "Hand.h"

#include <iostream>
#include <ostream>
#include <bits/locale_facets_nonio.h>

#include "optional"
#include "algorithm"

Hand::Hand() = default;

void Hand::deal_hand(Deck& deck, const int amount) {
    for (int i = 1; i <= amount; i++) {
        if (auto new_card = deck.deal()) {
            hand.push_back(*new_card);
        }//else for control safety if card is not returned
    }
}

size_t Hand::size_count_hand() const {
    return hand.size();
}

void Hand::display_hand() const {
    for (auto card : hand) {
        std::cout << card.to_string() << '\n';
    }
}

int Hand::value_count_hand() const {
    int value = 0;
    for (auto card : hand) {
        value += static_cast<int>(card.get_rank());
    }
    return value;
}
