//
// Created by vito on 30/03/2022.
//

#include "SortStatus.h"

#include <utility>
#include <iostream>

SortStatus::SortStatus(int s, std::vector<int> c, bool im, int com) {
    status = s;
    compared = std::move(c);
    inMotion = im;
    comparisons = com;
}

int SortStatus::getStatus() {
    return status;
}

bool SortStatus::getMotion() {
    return inMotion;
}

std::vector<int> SortStatus::lastCompared() {
    return compared;
}

void SortStatus::incrementComparisons(int num) {
    comparisons+=num;
}

int SortStatus::getComparisons() {
    return comparisons;
}

SortStatus::SortStatus(const SortStatus& x, std::vector<int> c) {
    this->inMotion = x.inMotion;
    this->comparisons = x.comparisons;
    this->status = x.status+1;
    this->compared = std::move(c);
}

void SortStatus::setMotion(bool x) {
    this->inMotion = x;
}
