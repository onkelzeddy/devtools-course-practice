// Copyright 2023 Ustinov Alexandr
#ifndef MODULES_LONGEST_INCREASING_SUBSEQUENCE_INCLUDE_LONGEST_INC_SUBSEQ_H_
#define MODULES_LONGEST_INCREASING_SUBSEQUENCE_INCLUDE_LONGEST_INC_SUBSEQ_H_

#include <vector>

// returns the longest increasing subsequence of 'array' i.e.
// vector 'v' of size 's' s.t. v[i] = array[k_i],
// 0 <= k_0 < k_1 < ... < k_{s-2} < k_{s-1} < array.size(),
// v[0] < v[1] < ... < v[s-2] < v[s-1]
//
// the found subsequence is lexicographically smallest among
// all longest increasing subsequences

std::vector<int> longestIncreasingSubsequence(const std::vector<int> &array);

#endif  // MODULES_LONGEST_INCREASING_SUBSEQUENCE_INCLUDE_LONGEST_INC_SUBSEQ_H_
