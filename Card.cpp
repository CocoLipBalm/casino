//
// Created by caidend on 6/29/2026.
//

#include "Card.h"

#include <unordered_map>

Card::Card(const Rank rank, const Suit suit)
        :rank(rank), suit(suit){}

std::string Card::to_string() const {
        std::unordered_map<Rank, std::string> const rank_map {
                {Two, "Two"}, {Three, "Three"},
                {Four, "Four"}, {Five, "Five"},
                {Six, "Six"}, {Seven, "Seven"},
                {Eight, "Eight"}, {Nine, "Nine"},
                {Ten, "Ten"}, {Jack, "Jack"},
                {Queen, "Queen"}, {King, "King"},
                {Ace, "Ace"}
        };
        std::unordered_map<Suit, std::string> const suit_map {
                {Diamond, "Diamond"}, {Heart, "Heart"},
                {Spade, "Spade"}, {Club, "Club"},
        };
        std::string result = rank_map.at(rank) + ", " + suit_map.at(suit);
        return result;
}

Rank Card::get_rank() const {
        return rank;
}

Suit Card::get_suit() const {
        return suit;
}


