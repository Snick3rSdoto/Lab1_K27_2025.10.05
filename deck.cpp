#include "deck.h"
#include <algorithm>
#include <ctime>

Deck::Deck(int suits)
    : numSuits(suits), index(0), rng(static_cast<unsigned>(std::time(nullptr))) {
    resetDeck();
}

void Deck::resetDeck() {
    cards.clear();
    for (int s = 0; s < numSuits; ++s)
        for (int r = 1; r <= 13; ++r)
            cards.push_back({s, r});
    std::shuffle(cards.begin(), cards.end(), rng);
    index = 0;
}

Deck::Card Deck::operator()() {
    if (index >= cards.size())
        resetDeck();
    return cards[index++];
}

// ---- Функції для роздачі карт і побудови стопок ----
std::vector<Deck::Card> dealCards(Deck& deck, int n) {
    std::vector<Deck::Card> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i)
        result.push_back(deck());
    return result;
}

std::vector<int> buildStacks(const std::vector<Deck::Card>& cards) {
    std::vector<int> stackLengths;
    if (cards.empty()) return stackLengths;

    int currentLength = 1;
    for (size_t i = 1; i < cards.size(); ++i) {
        if (cards[i] >= cards[i - 1])
            currentLength++;
        else {
            stackLengths.push_back(currentLength);
            currentLength = 1;
        }
    }
    stackLengths.push_back(currentLength);
    return stackLengths;
}

