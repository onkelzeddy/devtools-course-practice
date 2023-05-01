// Copyright 2023 Ustinov Alexandr

#include <cinttypes>
#include <algorithm>
#include <limits>
#include "include/longest_inc_subseq.h"

// returns the longest increasing subsequence of 'array' i.e.
// vector 'v' of size 's' s.t. v[i] = array[k_i],
// 0 <= k_0 < k_1 < ... < k_{s-2} < k_{s-1} < array.size(),
// v[0] < v[1] < ... < v[s-2] < v[s-1]
//
// the found subsequence is lexicographically smallest among
// all longest increasing subsequences

std::vector<int> longestIncreasingSubsequence(const std::vector<int> &array) {
    size_t longest_inc_subseq_len = 0;
    // index of previous element in increasing subsequence
    // which ends in element 'array[i]'
    std::vector<size_t> prev_element_idx(array.size());
    // smallest last element in increasing subsequence of length 'i'
    std::vector<int> last_element(array.size() + 1);
    // index of smallest last element in increasing subsequence of length 'i'
    std::vector<size_t> last_element_idx(array.size() + 1);
    // minimal value of type 'int'
    int min_element = std::numeric_limits<int>::min();
    int max_element = std::numeric_limits<int>::max();

    // initialize 'last_number[]':
    last_element[0] = min_element;
    for (size_t i = 1; i <= array.size(); ++i)
        last_element[i] = max_element;

    // dynamic programming to fill 'prev_element_idx[]', 'last_element[]'
    // and 'last_element_idx[]'
    for (size_t i = 0; i < array.size(); ++i) {
        if (array[i] == min_element) {
            // if MIN is minimal element then the only increasing sequence which
            // ends with MIN is 1-element sequence containing only MIN
            last_element[1] = min_element;
            last_element_idx[1] = i;
            // update maximal length if MIN is the 1st element of 'array[]'
            if (longest_inc_subseq_len == 0)
                longest_inc_subseq_len = 1;
            // no need to set previous element because MIN is always the first
        } else if (array[i] == max_element) {
            // if MAX is maximal element then its only place is in the end of
            // current longest subsequence
            if (last_element[longest_inc_subseq_len] != max_element) {
                ++longest_inc_subseq_len;
                last_element[longest_inc_subseq_len] = max_element;
                last_element_idx[longest_inc_subseq_len] = i;
            }
            prev_element_idx[i] = last_element_idx[longest_inc_subseq_len-1];
        } else {
            // find smallest index 'j' s.t. last_element[j] >= array[i]
            size_t j = std::lower_bound(last_element.begin(),
                        last_element.end(), array[i]) - last_element.begin();

            // consider 'array[i]' is an element of increasing subsequence,
            // then 'last_element[j-1]' is the previous element in it
            prev_element_idx[i] = last_element_idx[j-1];

            // update smallest last element in subsequence of length 'j'
            last_element[j] = array[i];
            last_element_idx[j] = i;

            // update maximal length of increasing subsequence
            if (j > longest_inc_subseq_len)
                longest_inc_subseq_len = j;
        }
    }

    // vector which contains longest increasing subsequence
    std::vector<int> longest_inc_subseq(longest_inc_subseq_len);
    // current index in 'prev_element_idx[]' as we go
    // from last element to first in longest increasing subsequence
    size_t current_idx = last_element_idx[longest_inc_subseq_len];

    // iterate from last element to first and
    // write the subsequence in correct order
    for (size_t i = 0; i < longest_inc_subseq_len; ++i) {
        longest_inc_subseq[longest_inc_subseq_len - 1 - i] = array[current_idx];
        current_idx = prev_element_idx[current_idx];
    }

    return longest_inc_subseq;
}
