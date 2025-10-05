#ifndef DECK_H
#define DECK_H

#include <vector>
#include <random>
#include <compare>

class Deck {
public:
    struct Card {
        int suit;  // номер масті
        int rank;  // 1..13

        auto operator<=>(const Card& other) const { return rank <=> other.rank; }
        bool operator==(const Card& other) const = default;
    };

private:
    int numSuits;                 // кількість мастей
    std::vector<Card> cards;      // поточна колода
    size_t index;                 // індекс наступної карти
    std::mt19937 rng;             // генератор випадкових чисел

    void resetDeck();             // формування нової колоди і тасування

public:
    Deck(int suits);              // конструктор

    Card operator()();            // повертає наступну карту
};

// ---- Функції, пов’язані з колодою ----
std::vector<Deck::Card> dealCards(Deck& deck, int n);
std::vector<int> buildStacks(const std::vector<Deck::Card>& cards);

#endif // DECK_H

