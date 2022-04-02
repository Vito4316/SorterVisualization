//
// Created by vito on 30/03/2022.
//

#ifndef GAME_SORTER_H
#define GAME_SORTER_H
#include <vector>
#include "SortStatusFIFO.h"
class Sorter {
public:
    SortStatusFIFO status = SortStatusFIFO();
    virtual void sort(std::vector<int> &array) = 0;
};


#endif //GAME_SORTER_H
