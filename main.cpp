#include "deck.h"
#include "stats.h"
#include <iostream>

int main() {
	int numSuits, numCards;
	std::cout << "Введіть кількість мастей: ";
	std::cin >> numSuits;
    Deck deck(numSuits);

    std::cout << "Введіть кількість карт для роздачі: ";
    std::cin >> numCards;

    auto cards = dealCards(deck, numCards);
    auto stacks = buildStacks(cards);
    auto stats = analyzeStacks(stacks);
    printStats(stats);

    return 0;
}

