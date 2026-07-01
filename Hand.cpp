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
#include <unordered_map>

Hand::Hand() = default;

void Hand::deal_hand(Deck& deck, const int amount) {
    for (int i = 1; i <= amount; i++) {
        if (auto new_card = deck.deal()) {
            hand.push_back(*new_card);
        } else {
            std::cout << "this message is because the deck is empty";
        }
    }
}

size_t Hand::size_count_hand() const {
    return hand.size();
}

void Hand::display_hand(const bool bj_dealer_toggle) const {
        for (Card card : hand) {
            std::cout << card.to_string() << " ";
            if (bj_dealer_toggle) {
                std::cout << "\x1b[31m" << "?" << "\x1b[0m" <<'\n';
                break;
            }
        }
}

void Hand::clear_hand() {
    hand.clear();
}

std::vector<Card> Hand::get_hand() const {
    return hand;
}

int Hand::get_BJ_value(bool bj_dealer_toggle) const {
    int total = 0;
    int ace_count = 0;
    std::unordered_map<Rank, int> const rank_map {
                        {Two, 2},{Three, 3},
                        {Four, 4},{Five, 5},
                        {Six, 6},{Seven, 7},
                        {Eight, 8},{Nine, 9},
                        {Ten, 10},{Jack, 10},
                        {Queen, 10},{King, 10},{Ace, 1}
    };
    for (const Card& card : hand) {
        if (bj_dealer_toggle) {
            return total += rank_map.at(card.get_rank());
        }
        if (card.get_rank() == Ace) {
            ace_count++;
        }
        total += rank_map.at(card.get_rank());
    }
    std::cout << "\x1b[33m" << total << "\x1b[0m";
    if (ace_count >= 1 && total + 10 <= 21) {
        total += 10;
        std::cout << "\x1b[33m" << "/" << total << "\x1b[0m";
    }
    return total;
}
