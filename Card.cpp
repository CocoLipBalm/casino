//
// Created by caidend on 6/29/2026.
//

#include "Card.h"

Card::Card(const Rank rank, const Suit suit)
        :rank(rank), suit(suit){}

std::string Card::to_string() const {
        std::string rank_text;
        std::string suit_text;

        switch (rank) {
                case Two: rank_text = "Two"; break;
                case Three: rank_text = "Three"; break;
                case Four: rank_text = "Four"; break;
                case Five: rank_text = "Five"; break;
                case Six: rank_text = "Six"; break;
                case Seven: rank_text = "Seven"; break;
                case Eight: rank_text = "Eight"; break;
                case Nine: rank_text = "Nine"; break;
                case Ten: rank_text = "Ten"; break;
                case Jack: rank_text = "Jack"; break;
                case Queen: rank_text = "Queen"; break;
                case King: rank_text = "King"; break;
                case Ace: rank_text = "Ace"; break;
                case RANK_BOUND: rank_text = "YOU MESSED UP IF YOU GOT HERE"; break;
                default: rank_text = "UNKNOWN"; break;
        }

        switch (suit) {
                case Heart: suit_text = "Heart"; break;
                case Diamond: suit_text = "Diamond"; break;
                case Club: suit_text = "Club"; break;
                case Spade: suit_text = "Spade"; break;
                case SUIT_BOUND: suit_text = "YOU MESSED UP IF YOU GOT HERE"; break;
                default: suit_text = "UNKNOWN"; break;
        }

        return "{" + rank_text + ", " + suit_text + "}";
}

Rank Card::get_rank() const  {
        return rank;
}
