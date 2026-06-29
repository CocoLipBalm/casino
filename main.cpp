//
// Created by caidend on 6/29/2026.
//

#include "Deck.h"
#include <iostream>


int main() {
    Deck deck;
    deck.build();
    deck.shuffle();
    std::cout << deck.deal()->to_string() << '\n';
    std::cout << deck.deal()->to_string() << '\n';
    std::cout << deck.deal()->to_string() << '\n';
    std::cout << deck.deal()->to_string() << '\n';


    return 0;
}