//
// Created by vito on 01/04/2022.
//

#ifndef GAME_SORTSTATUSFIFO_H
#define GAME_SORTSTATUSFIFO_H
#include "SortStatus.h"

class SortStatusFIFO {
    std::vector<SortStatus> stack = {};
    int status = 0;
    bool completed = false;

public:
    SortStatus nextStatus();
    void pushStatus(const SortStatus& x);
    bool isCompleted();
    void setCompleted(bool x);
};


#endif //GAME_SORTSTATUSFIFO_H
