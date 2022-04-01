//
// Created by vito on 30/03/2022.
//

#include <iostream>
#include "SorterQuickSort.h"

int SorterQuickSort::partition(std::vector<int> &arr, int start, int end, int &comparisons)
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
        if (i < pivotIndex && j > pivotIndex) { std::swap(arr[i++], arr[j--]);}

        this->status.pushStatus(SortStatus(arr, {i, j}, comparisons));

    }

    return pivotIndex;
}

void SorterQuickSort::quickSortR(std::vector<int> &arr, int start, int end, int &comparisons)
{
    // base case
    if (start >= end)
        return;
    // partitioning the array
    int p = partition(arr, start, end, comparisons);

    // Sorting the left part
    quickSortR(arr, start, p - 1, comparisons);

    // Sorting the right part
    quickSortR(arr, p + 1, end, comparisons);
    this->status.pushStatus(SortStatus(arr, {}, comparisons));
}

void SorterQuickSort::sort(std::vector<int> &array) {
    int comparisons = 0;
    SorterQuickSort::quickSortR(array, 0, array.size()-1, comparisons);
    this->status.setCompleted(true);
}