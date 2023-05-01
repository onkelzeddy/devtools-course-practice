// Copyright 2023 Selivankin Sergey

#pragma once

#include <vector>

//! @addtogroup binary-search
//! @{

/**
 * @brief A namespace which represents a binary search
 *
 * Binary search is a search algorithm that finds the position of
 * a target value within a sorted array.
 * Binary search runs in logarithmic time.
 */

namespace BinarySearch {
    /**
    * @brief find
    * @param[in] numbers is a vector of numbers
    * @param[in] target is a number for search in numbers
    */
    int find(const std::vector<int>& numbers, int target);
}

//! @}
