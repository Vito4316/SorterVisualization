//
// Created by vito on 30/03/2022.
//

#ifndef GAME_SORTSTATUS_H
#define GAME_SORTSTATUS_H
#include <vector>

class SortStatus {
    int status;
    int comparisons = 0;
    bool inMotion;
    std::vector<int> compared;

public:
    SortStatus(int s, std::vector<int> c, bool im, int com);
    SortStatus(const SortStatus& x, std::vector<int> c);
    int getStatus();
    bool getMotion();
    void incrementComparisons(int num);
    void setMotion(bool x);
    int getComparisons();
    std::vector<int> lastCompared();
};


#endif //GAME_SORTSTATUS_H
