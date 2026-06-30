//
// Created by caidend on 6/29/2026.
//

#include "Deck.h"

#include <iostream>
#include <ostream>
#include <random>
#include <algorithm>
#include <optional>
Deck::Deck() = default;

void Deck::build() {
    for (int i = 2; i < static_cast<int>(Rank::RANK_BOUND); i++) {
        for (int j = 1; j < static_cast<int>(Suit::SUIT_BOUND); j++) {
            auto card = Card(static_cast<Rank>(i), static_cast<Suit>(j));
            deck.push_back(card);
        }
    }
}

void Deck::display() const{
    for (auto &c : deck) {
        std::cout << c.to_string() << '\n';
    }
}

void Deck::shuffle() {
    std::mt19937 generator{std::random_device{}()};
    std::shuffle(deck.begin(), deck.end(),generator);
}

std::optional<Card> Deck::deal() {
    if (deck.empty()) {
        return std::nullopt;
    }
    const Card card = deck.back();
    deck.pop_back();
    return card;
}

void Deck::rebuildAndShuffle() {
    deck.clear();
    build();
    shuffle();
}

