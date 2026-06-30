//
// Created by caidend on 6/29/2026.
//

#ifndef CASINO_CARD_H
#define CASINO_CARD_H
#include <string>

enum Rank {
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    Jack = 11,
    Queen = 12,
    King = 13,
    Ace = 14,
    RANK_BOUND = 15,
};

enum Suit {
    Heart = 1,
    Diamond = 2,
    Club = 3,
    Spade = 4,
    SUIT_BOUND = 5,
};

class Card {
public:
    Card(Rank rank, Suit suit);

    std::string to_string() const;
    Rank get_rank() const;

private:
    Rank rank;
    Suit suit;
};


#endif //CASINO_CARD_H
