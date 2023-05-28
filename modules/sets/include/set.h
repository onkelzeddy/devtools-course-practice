// Copyright 2023 Uvarkin Ilya

#pragma once

#include <vector>

class Set{
 public:
    void insert(int elem);
    void erase(int elem);
    bool isExit(int elem);

    const std::vector<int> &getElems() const;

    explicit Set(const std::vector<int> &elems = {});

    friend Set operator & (const Set& set1, const Set& set2);
    friend Set operator | (const Set& set1, const Set& set2);
    friend Set operator - (const Set& set1, const Set& set2);
 private:
    std::vector<int> elems;
};
