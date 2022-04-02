//
// Created by vito on 30/03/2022.
//

#include "SortStatus.h"

#include <utility>
#include <iostream>

SortStatus::SortStatus(std::vector<int> &vs, std::vector<int> &ic, int c) {
    vectorStatus = std::vector<int>(vs);
    inComparison = std::vector<int>(ic);;
    comparisons = c;
}

SortStatus::SortStatus(std::vector<int> &vs, std::initializer_list<int> ic, int c) {
    vectorStatus = std::vector<int>(vs);
    inComparison = std::vector<int>(ic);;
    comparisons = c;
}


std::vector<int> SortStatus::getVectorStatus() {
    return vectorStatus;
}

std::vector<int> SortStatus::getInComparison() {
    return inComparison;
}

int SortStatus::getComparisons() {
    return comparisons;
}

