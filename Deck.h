//
// Created by caidend on 6/29/2026.
//

#ifndef CASINO_DECK_H
#define CASINO_DECK_H
#include <vector>
#include <optional>
#include "Card.h"


class Deck {
public:
    Deck();

    void build();
    void display() const;
    void shuffle();
    std::optional<Card> deal();
    void rebuildAndShuffle();

private:
    std::vector<Card> deck;
};


#endif //CASINO_DECK_H
