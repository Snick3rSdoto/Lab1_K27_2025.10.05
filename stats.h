#ifndef STATS_H
#define STATS_H

#include <vector>
#include <map>

struct Stats {
    int totalStacks;
    int mostFreqLen;
    double average;
    double median;
    std::map<int, double> percentages;
};

Stats analyzeStacks(const std::vector<int>& stackLengths);
void printStats(const Stats& s);

#endif

