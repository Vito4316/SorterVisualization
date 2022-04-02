//
// Created by vito on 30/03/2022.
//

#include <iostream>
#include "SorterBubbleSort.h"

void SorterBubbleSort::sort(std::vector<int> &array) {
    int comparisons = 0;

    for(int i = 0; i < array.size(); i++) {
        for(int j = 0; j < array.size()-1-i; j++) {
            if(array[j] > array[j+1])
                std::swap(array[j], array[j+1]);
            comparisons++;
            this->status.pushStatus(SortStatus(array, {j, j+1}, comparisons));
        }
    }
    this->status.pushStatus(SortStatus(array, {}, comparisons));
    this->status.setCompleted(true);
}