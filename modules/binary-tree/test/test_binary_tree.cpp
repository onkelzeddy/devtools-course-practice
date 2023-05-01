// Copyright 2023 Semenova Veronika

#include <gtest/gtest.h>
#include <vector>

#include "include/binary_tree.h"

using std::vector;

TEST(BTreeTest, Can_create_Node) {
  ASSERT_NO_THROW(Node ed);
}
TEST(BTreeTest,
  Can_create_Node_with_Value) {
  ASSERT_NO_THROW(Node ed(3));
}
TEST(BTreeTest,
  Create_Node_with_Value_correctly) {
  Node ed(3);
  EXPECT_EQ(ed.Value, 3);
}
TEST(BTreeTest,
  Replace_value_Node_correctly) {
  Node ed(3);
  ed.Value = 1;
  EXPECT_EQ(ed.Value, 1);
}
TEST(BTreeTest,
  Can_create_Node_with_parameter) {
  Node ed1;
  Node ed2(2);
  Node ed3(3);
  ASSERT_NO_THROW(Node ed(3, &ed1, &ed2, &ed3));
}
TEST(BTreeTest,
  Create_Node_with_parameter_correctly) {
  Node ed1(1);
  Node ed2(2);
  Node ed3(3);
  Node ed(3, &ed1, &ed2, &ed3);

  EXPECT_EQ((ed.Parent)->Value, 1);
  EXPECT_EQ((ed.Left)->Value, 2);
  EXPECT_EQ((ed.Right)->Value, 3);
}
TEST(BTreeTest,
  Can_create_Node_with_copy_constructor) {
  Node ed1;
  ASSERT_NO_THROW(Node ed(ed1));
}
TEST(BTreeTest,
  Create_Node_with_copy_constructor_correctly) {
  Node ed1(1);
  Node ed2(2);
  Node ed3(3, &ed1, &ed2);

  Node e(ed3);

  EXPECT_EQ(e.Value, 3);
  EXPECT_EQ(e.Left, nullptr);
  EXPECT_EQ(e.Right, nullptr);
  EXPECT_EQ(e.Parent, nullptr);
}

TEST(BTreeTest, Can_create_tree) {
  ASSERT_NO_THROW(BinaryTree t);
}
TEST(BTreeTest, C_create_t_with_Value) {
    ASSERT_NO_THROW(BinaryTree t(3));
}
TEST(BTreeTest,
 Can_not_resert_in_empty_tree) {
    BinaryTree t;
    ASSERT_ANY_THROW(t.Reset());
}
TEST(BTreeTest,
 Can_resert_in_not_empty_tree) {
    BinaryTree t(3);
    ASSERT_NO_THROW(t.Reset());
}
TEST(BTreeTest,
 Can_not_extract_Value_from_empty_tree) {
    BinaryTree t;
    ASSERT_ANY_THROW(t.GetValue());
}
TEST(BTreeTest,
 Can_extract_Value_from_tree) {
    BinaryTree t(3);
    t.Reset();
    ASSERT_NO_THROW(t.GetValue());
}
TEST(BTreeTest,
 Extract_Value_from_tree_correctly) {
    BinaryTree t(3);
    t.Reset();
    EXPECT_EQ(t.GetValue(), 3);
}
TEST(BTreeTest,
  Can_insert_node_in_empty_tree) {
  BinaryTree t;
  ASSERT_NO_THROW(t.Insert(2));
}
TEST(BTreeTest,
 Insert_node_in_empty_tree_correctly) {
  BinaryTree t;
  t.Insert(2);
  t.Reset();
  EXPECT_EQ(t.GetValue(), 2);
}
TEST(BTreeTest,
 Can_insert_node_in_tree) {
    BinaryTree t(3);
    ASSERT_NO_THROW(t.Insert(2));
}
TEST(BTreeTest,
 Can_find_value_in_empty_tree) {
    BinaryTree t;
    ASSERT_NO_THROW(t.Find(2));
}
TEST(BTreeTest,
 Find_value_in_empty_tree_correctly) {
    BinaryTree t;
    EXPECT_EQ(t.Find(2), nullptr);
}
TEST(BTreeTest,
 Can_find_value_in_tree) {
    BinaryTree t(2);
    ASSERT_NO_THROW(t.Find(2));
}
TEST(BTreeTest,
 Find_value_in_tree_correctly) {
    BinaryTree t(2);
    Node* n = t.Find(2);
    EXPECT_EQ(n->Value, 2);
}
TEST(BTreeTest,
 Can_not_insert_repeated_node_in_tree) {
    BinaryTree t(3);
    ASSERT_ANY_THROW(t.Insert(3));
}
TEST(BTreeTest,
 Can_SetNext_in_tree) {
    BinaryTree t(3);
    t.Reset();
    ASSERT_NO_THROW(t.SetNext());
}
TEST(BTreeTest,
 Insert_node_in_tree_corrertly) {
    BinaryTree t(3);
    t.Insert(8);
    t.Reset();
    EXPECT_EQ(t.GetValue(), 3);
    t.SetNext();
    EXPECT_EQ(t.GetValue(), 8);
}
TEST(BTreeTest,
 Insert_node_in_tree_corrertly2) {
    BinaryTree t(3);
    t.Insert(1);
    t.Reset();
    EXPECT_EQ(t.GetValue(), 1);
    t.SetNext();
    EXPECT_EQ(t.GetValue(), 3);
}
TEST(BTreeTest,
 Can_create_tree_from_vector_of_values) {
    std::vector<int> val = { -2, 2, 5, 3, -1, 7, 8, 6 };
    ASSERT_NO_THROW(BinaryTree t(val));
}
TEST(BTreeTest,
 Create_tree_from_vector_of_values_corrertly) {
    std::vector<int> val = { -2, 5, 3 };
    BinaryTree t(val);
    t.Reset();
    EXPECT_EQ(t.GetValue(), -2);
    t.SetNext();
    EXPECT_EQ(t.GetValue(), 3);
    t.SetNext();
    EXPECT_EQ(t.GetValue(), 5);
}
TEST(BTreeTest,
 Can_not_delete_node_in_empty_tree) {
    BinaryTree t;
    ASSERT_ANY_THROW(t.Delete(2));
}
TEST(BTreeTest,
 Find_value_in_tree_from_vector_of_values_corrertly) {
    std::vector<int> val = { -2, 2, 5, 3, -1, 7, 8, 6 };
    BinaryTree t(val);
    Node* res = t.Find(-1);
    EXPECT_EQ(res->Value, -1);
}
TEST(BTreeTest,
 Can_delete_node_in_tree) {
    BinaryTree t(3);
    ASSERT_NO_THROW(t.Delete(3));
}
TEST(BTreeTest,
 Delete_node_in_tree_corrertly) {
    BinaryTree t(3);
    t.Delete(3);
    EXPECT_EQ(t.Find(3), nullptr);
}
TEST(BTreeTest,
 Can_delete_node_without_descendants) {
    BinaryTree t({ 1, 5, 4, -3, 7, -4 });
    ASSERT_NO_THROW(t.Delete(7));
}
TEST(BTreeTest,
 Delete_node_without_descendants_corrertly) {
    BinaryTree t({ 1, 5, 4, -3, 7, -4 });
    t.Delete(7);
    EXPECT_EQ(t.Find(7), nullptr);
}
TEST(BTreeTest,
 Can_delete_node_with_one_descendants) {
    BinaryTree t({ 1, 5, 4, -3, 7, -4 });
    ASSERT_NO_THROW(t.Delete(-3));
}
TEST(BTreeTest,
 Delete_node_with_one_descendants_corrertly) {
    BinaryTree t({ 1, 5, 4, -3, 7, -4 });
    t.Delete(-3);
    EXPECT_EQ(t.Find(-3), nullptr);
}
TEST(BTreeTest,
 Can_delete_node_with_two_descendants) {
    BinaryTree t({ 1, 5, 4, -3, 7, -2 });
    ASSERT_NO_THROW(t.Delete(5));
}
TEST(BTreeTest,
 Delete_node_with_two_descendants_corrertly) {
    BinaryTree t({ 1, 5, 4, -3, 7, -2 });
    t.Delete(5);
    EXPECT_EQ(t.Find(5), nullptr);
}
TEST(BTreeTest,
 Can_delete_a_root) {
    BinaryTree t({ 1, 5, 4, -3, 7, -2 });
    ASSERT_NO_THROW(t.Delete(1));
}
TEST(BTreeTest,
 Delete_a_root_corrertly) {
    BinaryTree t({ 1, 5, 4, -3, 7, -2 });
    t.Delete(1);
    EXPECT_EQ(t.Find(1), nullptr);
}
TEST(BTreetest,
 Can_SetNext_Parent) {
    BinaryTree t({ 1, 5, 4, -3, 7, -2 });
    t.Reset();
    t.SetNext();
    t.SetNext();
    ASSERT_NO_THROW(t.SetNext());
}
TEST(BTreetest,
 Can_IsEnd) {
    BinaryTree t({ 1, 5, 4});
    t.Reset();
    ASSERT_NO_THROW(t.IsEnd());
}
