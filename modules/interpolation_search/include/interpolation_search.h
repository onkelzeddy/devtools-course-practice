// Copyright 2023 Mironov Nikita

#ifdef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_

class interpolation_search {
private:
    int[] target_array;
    int array_size;
    int search_target;
    void sort_target_array();
    bool target_array_is_sorted();
public:
    interpolation_search(const int[] array_for_search);
    interpolation_search(const int[] array_for_search,
        const int target_for_search);
    void set_array(int[] array);
    void set_target(int new_target_for_search);
    bool search();
};

#endif // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
