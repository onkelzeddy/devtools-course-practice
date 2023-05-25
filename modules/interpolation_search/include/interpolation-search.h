// Copyright 2023 Mironov Nikita

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_

#include <vector>

class interpolationSearch {
 public:
    explicit interpolationSearch(const std::vector<int>);
    void set_vector(const std::vector<int>);
    int search(const int);

 private:
    std::vector<int> original_target_vector;
    std::vector<int> target_vector;
    int vector_size;
    void sort_target_vector();
    bool target_vector_is_sorted();
};


#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
