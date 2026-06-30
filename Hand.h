//
// Created by caide on 6/29/2026.
//

#ifndef CASINO_HAND_H
#define CASINO_HAND_H
#include <vector>

#include "Card.h"


class Hand {
public:
    Hand();

    void deal_hand(Deck& deck, int amount);
    [[nodiscard]] size_t size_count_hand() const;
    void display_hand() const;
    [[nodiscard]] int value_count_hand() const;
    void clear_hand();
    std::vector<Card> get_hand() const;

private:
    std::vector<Card> hand;
};


#endif //CASINO_HAND_H
