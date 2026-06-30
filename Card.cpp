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

int Card::get_BJ_value(const int value) const {
        std::unordered_map<Rank, int> rank_map {
                {Two, 2},{Three, 3},
                {Four, 4},{Five, 5},
                {Six, 6},{Seven, 7},
                {Eight, 8},{Nine, 9},
                {Ten, 10},{Jack, 10},
                {Queen, 10},{King, 10},{Ace, 11}
        };
        if (value >= 11) {
                rank_map.at(Ace) = 1;
        }
        return rank_map.at(rank);
        }


