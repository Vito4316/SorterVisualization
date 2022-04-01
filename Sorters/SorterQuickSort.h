//
// Created by vito on 30/03/2022.
//

#ifndef GAME_SORTERQUICKSORT_H
#define GAME_SORTERQUICKSORT_H
#include "Sorter.h"
#include "SortStatus.h"

class SorterQuickSort: public Sorter {
    void sort(std::vector<int> &array) override;
private:
    int partition(std::vector<int> &arr, int start, int end, int& comparisons);
    void quickSortR(std::vector<int> &arr, int start, int end, int& comparisons);
};


#endif //GAME_SORTERQUICKSORT_H
