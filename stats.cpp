#include "stats.h"
#include <iostream>
#include <algorithm>

Stats analyzeStacks(const std::vector<int>& stackLengths) {
    Stats s{};
    s.totalStacks = stackLengths.size();
    if (s.totalStacks == 0) return s;

    // Частоти
    std::map<int, int> freq;
    for (int len : stackLengths) freq[len]++;

    // Відсотки
    for (auto& [len, count] : freq)
        s.percentages[len] = 100.0 * count / s.totalStacks;

    // Найчастіша довжина
    s.mostFreqLen = std::max_element(freq.begin(), freq.end(),
        [](auto& a, auto& b) { return a.second < b.second; })->first;

    // Середнє
    double sum = 0;
    for (int len : stackLengths) sum += len;
    s.average = sum / s.totalStacks;

    // Медіана
    std::vector<int> sorted = stackLengths;
    std::sort(sorted.begin(), sorted.end());
    int m = sorted.size();
    if (m % 2 == 1)
        s.median = sorted[m / 2];
    else
        s.median = (sorted[m / 2 - 1] + sorted[m / 2]) / 2.0;

    return s;
}

void printStats(const Stats& s) {
    std::cout << "Статистика стопок:\n";
    for (auto& [len, perc] : s.percentages)
        std::cout << "Довжина " << len << ": " << perc << "% стопок\n";

    std::cout << "\nКількість стопок: " << s.totalStacks << "\n";
    std::cout << "Найчастіша довжина стопки: " << s.mostFreqLen << "\n";
    std::cout << "Середня довжина стопки: " << s.average << "\n";
    std::cout << "Медіанна довжина стопки: " << s.median << "\n";
}

