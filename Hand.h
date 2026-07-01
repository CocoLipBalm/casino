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
    void display_hand(bool bj_dealer_toggle = false) const;
    void clear_hand();
    [[nodiscard]] std::vector<Card> get_hand() const;
    [[nodiscard]] int get_BJ_value(bool bj_dealer_toggle = false) const;

private:
    std::vector<Card> hand;
};


#endif //CASINO_HAND_H
