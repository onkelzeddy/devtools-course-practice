// Copyright 2023 Mironov Nikita

#include "include/interpolation_search.h"

interpolationSearch::interpolationSearch(const std::vector<int> new_target_vector) {
    if(new_target_vector.empty()){
        throw("Vector can't be empty.");
    }
    vector_size = new_target_vector.size();
    target_vector = new_target_vector;
}

void interpolationSearch::set_vector(const std::vector<int> new_target_vector) {
    if(new_target_vector.empty()){
        throw("Vector can't be empty.");
    }
    vector_size = new_target_vector.size();
    target_vector = new_target_vector;
}

int interpolationSearch::search(int search_target) {
    int left_border = 0;
    int middle;
    int right_border = vector_size - 1;

    if(vector_size == 1) {
        if(target_vector[0] == search_target){
            return 0;
        } else {
            return -1;
        }
    }

    if(!target_vector_is_sorted()) {
        sort_target_vector();
    }

    while (target_vector[left_border] < search_target && target_vector[right_border] > search_target) {
        if(target_vector[right_border] == target_vector[left_border]) {
            break;
        }

        middle = left_border + ((search_target - target_vector[left_border]) * (right_border - left_border)) /
         (target_vector[right_border] - target_vector[left_border]);

        if(target_vector[middle] < search_target) {
            left_border = middle + 1;
        }
        else if(target_vector[middle] > search_target) {
            right_border = middle - 1;
        } else {
            return middle;
        }
        
    }

    if(target_vector[left_border] == search_target) {
        return left_border;
    }
    if(target_vector[right_border] == search_target) {
        return right_border;
    }

    return -1;
}

void interpolationSearch::sort_target_vector() {
    if(vector_size == 1) {
        return;
    }

    int i = 1;
    int j = 2;
    int tmp;

    while (i < vector_size)
    {
        if(target_vector[i - 1] < target_vector[i]) {
            i = j;
            j = j + 1;
        } else {
            tmp = target_vector[i];
            target_vector[i] = target_vector[i - 1];
            target_vector[i - 1] = tmp;
            i = i - 1;
            if(i == 0) {
                i = j;
                j = j + 1;
            }
        }
    }
}

bool interpolationSearch::target_vector_is_sorted() {

    for(int i = 0; i < vector_size - 1; i++) {
        if(target_vector[i] > target_vector[i+1]) {
            return false;
        }
    }

    return true;
}