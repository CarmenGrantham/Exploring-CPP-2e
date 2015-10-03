//
// Created by carmen on 3/10/2015.
//
#include <list>
#include <iostream>

#include "card.h"
#include "randomint.h"

int main() {
    std::list<card> deck(52);
    std::generate(deck.begin(), deck.end(), card_generator());

    randomint picker{0, deck.size() - 1};
    for (int i{0}; i != 10; ++i) {
        std::list<card>::iterator pick {deck.begin()};
        std::advance(pick, randomint{0, deck.size() - 1})
        card computer_card{*pick};
        deck.erase(pick);

        std::cout << "I picked " << computer_card << '\n';

        pick = std::next(deck.begin(), randomint{0, deck.size()-1}());
        card user_card{*pick};
        deck.erase(pick);
        std::cout << "You picked " << user_card << '\n';

        if (acehigh_compare(computer_card, user_card)) {
            std::cout << "You win.\n";
        } else {
            std::cout << "I win.\n";
        }
    }
}
