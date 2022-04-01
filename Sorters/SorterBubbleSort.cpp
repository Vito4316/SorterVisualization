//
// Created by vito on 30/03/2022.
//

#include <iostream>
#include "SorterBubbleSort.h"

void SorterBubbleSort::sort(std::vector<int> &array) {
    int status = 0;
    for(int i = 0; i < array.size(); i++) {
        for(int j = 0; j < array.size()-1-i; j++) {
            if(array[j] > array[j+1])
                std::swap(array[j], array[j+1]);
            if(this->status.getStatus() < status) {
                std::vector<int> x(0);
                x.push_back(j);
                x.push_back(j+1);
                this->status = SortStatus(this->status, x);
                this->status.incrementComparisons(1);
                return;
            }
            status++;
        }
    }

    this->status = SortStatus(status, std::vector<int>(), false, this->status.getComparisons());
}