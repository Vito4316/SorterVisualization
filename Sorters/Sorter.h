//
// Created by vito on 30/03/2022.
//

#ifndef GAME_SORTER_H
#define GAME_SORTER_H
#include <vector>
#include "SortStatus.h"
class Sorter {
public:
    SortStatus status = SortStatus(0, std::vector<int>(), true, 0);
    virtual void sort(std::vector<int> &array) = 0;
};


#endif //GAME_SORTER_H
