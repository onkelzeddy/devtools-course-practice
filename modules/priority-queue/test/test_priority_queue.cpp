// Copyright 2023 Zorin Oleg

#include <gtest/gtest.h>
#include "include/priority_queue.h"

class PriorityQueueIntTest : public ::testing::Test {
 protected:
  PriorityQueue<int> Q;
  virtual void SetUp() {
    Q.put(15);
    Q.put(1);
    Q.put(-3);
    Q.put(100);
    Q.put(10);
    Q.put(-2);
    Q.put(-15);
  }
  virtual void TearDown() {}
};

TEST(PriorityQueueTest, Can_Construct) {
  ASSERT_NO_THROW(PriorityQueue<int> Q);
}

TEST(PriorityQueueTest, Can_Copy) {
  PriorityQueue<int> Q1;

  ASSERT_NO_THROW(PriorityQueue<int> Q2(Q1));
}

TEST(PriorityQueueTest, Can_Assign_Copy_Other) {
  PriorityQueue<int> Q1;

  PriorityQueue<int> Q2;

  ASSERT_NO_THROW(Q2 = Q1);
}

TEST(PriorityQueueTest, Can_Assign_Copy_This) {
  PriorityQueue<int> Q;

  ASSERT_NO_THROW(Q = Q);
}

TEST(PriorityQueueTest, Size_Null_When_Empty) {
  PriorityQueue<int> Q;

  size_t size = Q.size();

  ASSERT_EQ((size_t) 0, size);
}

TEST(PriorityQueueTest, Cant_Top_When_Empty) {
  PriorityQueue<int> Q;

  ASSERT_ANY_THROW(Q.top());
}

TEST(PriorityQueueTest, Cant_Pop_When_Empty) {
  PriorityQueue<int> Q;

  ASSERT_ANY_THROW(Q.pop());
}

TEST(PriorityQueueTest, Cant_Get_When_Empty) {
  PriorityQueue<int> Q;

  ASSERT_ANY_THROW(Q.get());
}

TEST(PriorityQueueTest, Can_Put_One_Element) {
  PriorityQueue<int> Q;
  const int value = 5;

  Q.put(value);

  ASSERT_EQ(value, Q.top());
}

TEST(PriorityQueueTest, Can_Get_One_Element) {
  PriorityQueue<int> Q;
  const int expectedValue = 5;
  Q.put(expectedValue);

  const int value = Q.get();

  ASSERT_EQ(expectedValue, value);
}

TEST(PriorityQueueTest, Empty_When_Pop_Remove_Last_Element) {
  PriorityQueue<int> Q;
  const int value = 5;
  Q.put(value);

  Q.pop();

  ASSERT_TRUE(Q.empty());
}

TEST(PriorityQueueTest, Empty_When_Get_Remove_Last_Element) {
  PriorityQueue<int> Q;
  const int value = 5;
  Q.put(value);

  Q.get();

  ASSERT_TRUE(Q.empty());
}

TEST_F(PriorityQueueIntTest, Top_Return_Highest_Element) {
  ASSERT_EQ(100, Q.top());
}

TEST_F(PriorityQueueIntTest, Get_Return_Highest_Element) {
  ASSERT_EQ(100, Q.get());
}

TEST_F(PriorityQueueIntTest, Pop_Remove_Highest_Element) {
  Q.pop();

  ASSERT_NE(100, Q.top());
}

TEST_F(PriorityQueueIntTest, Pop_Change_Size) {
  size_t size = Q.size();

  Q.pop();

  ASSERT_EQ(size - 1, Q.size());
}

TEST_F(PriorityQueueIntTest, Get_Change_Size) {
  size_t size = Q.size();

  int value = Q.get();

  ASSERT_EQ(size - 1, Q.size());
}

TEST_F(PriorityQueueIntTest, Top_Not_Change_Size) {
  size_t size = Q.size();

  const int &value = Q.top();

  ASSERT_EQ(size, Q.size());
}

TEST_F(PriorityQueueIntTest, Empty_When_Clear) {
  Q.clear();

  ASSERT_TRUE(Q.empty());
}

TEST_F(PriorityQueueIntTest, Copy_Top_Same) {
  PriorityQueue<int> copyQ(Q);

  const int &value = Q.top();
  const int &copy_value = copyQ.top();

  ASSERT_EQ(value, copy_value);
}

TEST_F(PriorityQueueIntTest, Assign_Copy_Top_Same) {
  PriorityQueue<int> copyQ = Q;

  const int &value = Q.top();
  const int &copy_value = copyQ.top();

  ASSERT_EQ(value, copy_value);
}

TEST_F(PriorityQueueIntTest, Copy_Has_Own_Memory) {
  PriorityQueue<int> copyQ(Q);

  Q.pop();

  ASSERT_NE(copyQ.top(), Q.top());
}

TEST_F(PriorityQueueIntTest, Assign_Copy_Has_Own_Memory) {
  PriorityQueue<int> copyQ = Q;

  Q.pop();

  ASSERT_NE(copyQ.top(), Q.top());
}

TEST(TestPriorityQueue, Can_creat_PriorityQueue_with_parameter) {
    ASSERT_NO_THROW(PriorityQueue<int> Q2(3));
}

TEST(TestPriorityQueue, Creat_PriorityQueue_with_parameter_correctly) {
    PriorityQueue<int> Q2(3);
    ASSERT_EQ(Q2.top(), 3);
}
