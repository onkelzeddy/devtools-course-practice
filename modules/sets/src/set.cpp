// Copyright 2023 Uvarkin Ilya

#include <algorithm>
#include "../include/set.h"

Set::Set(const std::vector<int> &elems) : elems(elems) {}

const std::vector<int> &Set::getElems() const {
  return elems;
}

void Set::insert(int elem) {
  elems.insert(std::upper_bound(elems.begin(), elems.end(), elem), elem);
}

void Set::erase(int elem) {
  auto it = std::find(elems.begin(), elems.end(), elem);
  if (it != elems.end()) {
    elems.erase(it);
  }
}

bool Set::isExit(int elem) {
  auto it = std::find(elems.begin(), elems.end(), elem);
  return it != elems.end();
}

Set operator&(const Set &set1, const Set &set2) {
  Set set;

  size_t index1 = 0;
  size_t index2 = 0;
  while (index1 < set1.elems.size() && index2 < set2.elems.size()) {
    if (set1.elems[index1] == set2.elems[index2]) {
      set.elems.push_back(set1.elems[index1++]);
      index2++;
      continue;
    }

    set1.elems[index1] < set2.elems[index2] ? index1++ : index2++;
  }

  return set;
}

Set operator|(const Set &set1, const Set &set2) {
  Set set;

  size_t index1 = 0;
  size_t index2 = 0;
  while (index1 < set1.elems.size() || index2 < set2.elems.size()) {
    if (index1 >= set1.elems.size()) {
      set.elems.push_back(set2.elems[index2++]);
      continue;
    }

    if (index2 >= set2.elems.size()) {
      set.elems.push_back(set1.elems[index1++]);
      continue;
    }

    if (set1.elems[index1] == set2.elems[index2]) {
      set.elems.push_back(set1.elems[index1++]);
      index2++;
    }

    if (set1.elems[index1] < set2.elems[index2]) {
      set.elems.push_back(set1.elems[index1++]);
    } else {
      set.elems.push_back(set2.elems[index2++]);
    }
  }

  return set;
}

Set operator-(const Set &set1, const Set &set2) {
  Set set;

  size_t index2 = 0;
  for (size_t i = 0; i < set1.getElems().size(); ++i) {
    if (index2 >= set2.getElems().size() ||
    set1.getElems()[i] < set2.getElems()[index2]) {
      set.elems.push_back(set1.getElems()[i]);
      continue;
    }

    index2++;
  }

  return set;
}
