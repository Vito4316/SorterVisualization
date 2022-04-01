//
// Created by vito on 30/03/2022.
//

#include <iostream>
#include "SorterQuickSort.h"

int SorterQuickSort::partition(std::vector<int> &arr, int start, int end, int &status, int &comparisons)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
        comparisons++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) { i++; comparisons++;}
        while (arr[j] > pivot) { j--; comparisons++;}
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
            this->status.incrementComparisons(comparisons - this->status.getComparisons());
        }

        if(this->status.getStatus() < status) {
            std::vector<int> x(0);
            x.push_back(i);
            x.push_back(j);
            x.push_back(pivotIndex);
            this->status = SortStatus(this->status, x);
            return -1;
        }
        status++;

    }

    return pivotIndex;
}

int SorterQuickSort::quickSortR(std::vector<int> &arr, int start, int end, int &status, int &comparisons)
{
    // base case
    if (start >= end)
        return 2;
    // partitioning the array
    int p = partition(arr, start, end, status, comparisons);
    if(p == -1) return -1;

    int x;
    // Sorting the left part
    x = quickSortR(arr, start, p - 1, status, comparisons);

    if(x == -1)
        return -1;
    // Sorting the right part
    x = quickSortR(arr, p + 1, end, status, comparisons);

    if(x == -1)
        return -1;

    return 2;
}

void SorterQuickSort::sort(std::vector<int> &array) {
    int status = 0;
    int comparisons = 0;
    if(this->status.getMotion()) {
        int x = quickSortR(array, 0, (int) array.size() - 1, status, comparisons);
        if (x == 2) this->status = SortStatus(status, std::vector<int>(), false, this->status.getComparisons());
    }
}