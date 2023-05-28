// Copyright 2023 Uvarkin Ilya

#include <gtest/gtest.h>
#include <cstring>
#include "include/set.h"

TEST(Set, assert_no_throw_in_default_constructor) {
  ASSERT_NO_THROW(Set set);
}

TEST(Set, assert_no_throw_in_constructor) {
  ASSERT_NO_THROW(Set set(std::vector<int>{1, 2, 3, 42}));
}

TEST(Set, elem_not_exist) {
  Set set;

  EXPECT_EQ(set.isExit(42), false);
}

TEST(Set, elem_exist) {
  Set set;
  set.insert(42);
  EXPECT_EQ(set.isExit(42), true);
}

TEST(Set, insert_elem) {
  Set set;
  set.insert(42);
  EXPECT_EQ(set.isExit(42), true);
}

TEST(Set, erase_elem) {
  Set set;

  set.insert(42);
  set.erase(42);

  EXPECT_EQ(set.isExit(42), false);
}

TEST(Set, set_union) {
  Set set1(std::vector<int>{1, 3, 7});
  Set set2(std::vector<int>{1, 2, 3, 15});
  std::vector<int> ElemsExpect = std::vector<int>{1, 2, 3, 7, 15};

  Set set = set1 | set2;

  ASSERT_EQ(set.getElems().size(), ElemsExpect.size());
  for (size_t i = 0; i < set.getElems().size(); ++i) {
      EXPECT_EQ(set.getElems()[i], ElemsExpect[i]);
  }
}

TEST(Set, set_union_2) {
  Set set1(std::vector<int>{1, 3, 7, 30});
  Set set2(std::vector<int>{1, 2, 3, 15});
  std::vector<int> ElemsExpect = std::vector<int>{1, 2, 3, 7, 15, 30};

  Set set = set1 | set2;

  ASSERT_EQ(set.getElems().size(), ElemsExpect.size());
  for (size_t i = 0; i < set.getElems().size(); ++i) {
    EXPECT_EQ(set.getElems()[i], ElemsExpect[i]);
  }
}

TEST(Set, set_intersection) {
  Set set1(std::vector<int>{1, 2, 3, 4, 7});
  Set set2(std::vector<int>{1, 3, 15});
  std::vector<int> ElemsExpect = std::vector<int>{1, 3};

  Set set = set1 & set2;

  ASSERT_EQ(set.getElems().size(), ElemsExpect.size());
  for (size_t i = 0; i < set.getElems().size(); ++i) {
    EXPECT_EQ(set.getElems()[i], ElemsExpect[i]);
  }
}

TEST(Set, set_difference) {
  Set set1(std::vector<int>{1, 2, 3, 4, 7});
  Set set2(std::vector<int>{1, 3, 15});
  std::vector<int> ElemsExpect = std::vector<int>{2, 4, 7};

  Set set = set1 - set2;

  ASSERT_EQ(set.getElems().size(), ElemsExpect.size());
  for (size_t i = 0; i < set.getElems().size(); ++i) {
    EXPECT_EQ(set.getElems()[i], ElemsExpect[i]);
  }
}


