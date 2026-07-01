//
// Created by caidend on 6/29/2026.
//

#include "Card.h"

#include <unordered_map>

Card::Card(const Rank rank, const Suit suit)
        : rank(rank), suit(suit) {}

std::string Card::to_string() const {
        const std::unordered_map<Rank, std::string> rank_map {
                    {Two, "Two"}, {Three, "Three"},
                    {Four, "Four"}, {Five, "Five"},
                    {Six, "Six"}, {Seven, "Seven"},
                    {Eight, "Eight"}, {Nine, "Nine"},
                    {Ten, "Ten"}, {Jack, "Jack"},
                    {Queen, "Queen"}, {King, "King"},
                    {Ace, "Ace"}
        };

        const std::unordered_map<Suit, std::string> suit_map {
                    {Diamond, "Diamond"}, {Heart, "Heart"},
                    {Spade, "Spade"}, {Club, "Club"}
        };

        return "\x1b[31m(" + rank_map.at(rank) + ", " + suit_map.at(suit) + ")\x1b[0m";
}

Rank Card::get_rank() const {
        return rank;
}

Suit Card::get_suit() const {
        return suit;
}
