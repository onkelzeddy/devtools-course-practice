// Copyright 2023 Selivankin Sergey

#include "include/binary_search.h"

int BinarySearch::find(const std::vector<int> &numbers, int target) {
    int left = 0;
    int right = static_cast<int>(numbers.size()) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (numbers[mid] == target) {
            return mid;
        }
        if (numbers[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
