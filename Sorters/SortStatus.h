//
// Created by vito on 30/03/2022.
//

#ifndef GAME_SORTSTATUS_H
#define GAME_SORTSTATUS_H
#include <vector>

class SortStatus {
    std::vector<int> vectorStatus = {};
    std::vector<int> inComparison = {};
    int comparisons = 0;
public:
    SortStatus(std::vector<int> &vs, std::vector<int> &ic, int c);
    SortStatus(std::vector<int> &vs, std::initializer_list<int> ic, int c);
    SortStatus() = default;
    std::vector<int> getVectorStatus();
    std::vector<int> getInComparison();
    int              getComparisons();
};


#endif //GAME_SORTSTATUS_H
