#include "unit_tests.h"

TEST(ListModifiersMerge, TwoListsCorrectInt) {
  s21::list<int> dest = {1, 2, 3, 4, 5};
  s21::list<int> src = {30, 20, 10};
  s21::list<int> compare = {1, 2, 3, 4, 5, 30, 20, 10};
  dest.merge(src);
  EXPECT_TRUE(EqualLists(dest, compare));
}

TEST(ListModifiersMerge, TwoListsCorrectChar) {
  s21::list<char> dest = {'a', 'b', 'c', 'd', 'e'};
  s21::list<char> src = {'Z', 'Y', 'X'};
  s21::list<char> compare = {'Z', 'Y', 'X', 'a', 'b', 'c', 'd', 'e'};
  dest.merge(src);
  EXPECT_TRUE(EqualLists(dest, compare));
}

TEST(ListModifiersMerge, TwoListsCorrectStr) {
  s21::list<std::string> dest = {"sus", "amogus", "ABOBA", "sus"};
  s21::list<std::string> src = {"sugoma", "BAOBAB", "yeet"};
  s21::list<std::string> compare = {"sugoma", "BAOBAB", "sus", "amogus",
                                    "ABOBA",  "sus",    "yeet"};
  dest.merge(src);
  EXPECT_TRUE(EqualLists(dest, compare));
}

TEST(ListModifiersMerge, TwoListsCompareInt) {
  s21::list<int> s21_dest = {1, 2, 3, 4, 5};
  s21::list<int> s21_src = {30, 20, 10};
  std::list<int> std_dest = {1, 2, 3, 4, 5};
  std::list<int> std_src = {30, 20, 10};
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(EqualLists(s21_dest, std_dest));
}

TEST(ListModifiersMerge, TwoListsCompareChar) {
  s21::list<char> s21_dest = {'a', 'b', 'c', 'd', 'e'};
  s21::list<char> s21_src = {'Z', 'Y', 'X'};
  std::list<char> std_dest = {'a', 'b', 'c', 'd', 'e'};
  std::list<char> std_src = {'Z', 'Y', 'X'};
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(EqualLists(s21_dest, std_dest));
}

TEST(ListModifiersMerge, TwoListsCompareStr) {
  s21::list<std::string> s21_dest = {"sus", "amogus", "ABOBA", "sus"};
  s21::list<std::string> s21_src = {"sugoma", "BAOBAB", "yeet"};
  std::list<std::string> std_dest = {"sus", "amogus", "ABOBA", "sus"};
  std::list<std::string> std_src = {"sugoma", "BAOBAB", "yeet"};
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(EqualLists(s21_dest, std_dest));
}

TEST(ListModifiersMerge, TwoListsRandomOrderCorrectInt) {
  s21::list<int> dest = {5, 9, 1, 3, 3};
  s21::list<int> src = {8, 7, 2, 3, 4, 4};
  s21::list<int> compare = {5, 8, 7, 2, 3, 4, 4, 9, 1, 3, 3};
  dest.merge(src);
  EXPECT_TRUE(EqualLists(dest, compare));
}

TEST(ListModifiersMerge, TwoListsRandomOrderCompareInt) {
  s21::list<int> s21_dest = {5, 9, 1, 3, 3};
  s21::list<int> s21_src = {8, 7, 2, 3, 4, 4};
  std::list<int> std_dest = {5, 9, 1, 3, 3};
  std::list<int> std_src = {8, 7, 2, 3, 4, 4};
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(EqualLists(s21_dest, std_dest));
}

TEST(ListModifiersMerge, DestListEmptyCorrectInt) {
  s21::list<int> dest;
  s21::list<int> src = {1, 2};
  s21::list<int> compare(src);
  dest.merge(src);
  EXPECT_TRUE(EqualLists(dest, compare));
  EXPECT_TRUE(src.empty());
}

TEST(ListModifiersMerge, DestListEmptyCorrectChar) {
  s21::list<char> dest;
  s21::list<char> src = {'A', 'B'};
  s21::list<char> compare(src);
  dest.merge(src);
  EXPECT_TRUE(EqualLists(dest, compare));
  EXPECT_TRUE(src.empty());
}

TEST(ListModifiersMerge, DestListEmptyCorrectStr) {
  s21::list<std::string> dest;
  s21::list<std::string> src = {"sus", "amogus"};
  s21::list<std::string> compare(src);
  dest.merge(src);
  EXPECT_TRUE(EqualLists(dest, compare));
  EXPECT_TRUE(src.empty());
}

TEST(ListModifiersMerge, DestListEmptyCompareInt) {
  s21::list<int> s21_dest;
  s21::list<int> s21_src = {30, 20, 10};
  std::list<int> std_dest;
  std::list<int> std_src = {30, 20, 10};
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(EqualLists(s21_dest, std_dest));
  EXPECT_TRUE(s21_src.empty() == std_src.empty());
}

TEST(ListModifiersMerge, DestListEmptyCompareChar) {
  s21::list<char> s21_dest;
  s21::list<char> s21_src = {'Z', 'Y', 'X'};
  std::list<char> std_dest;
  std::list<char> std_src = {'Z', 'Y', 'X'};
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(EqualLists(s21_dest, std_dest));
  EXPECT_TRUE(s21_src.empty() == std_src.empty());
}

TEST(ListModifiersMerge, DestListEmptyCompareStr) {
  s21::list<std::string> s21_dest;
  s21::list<std::string> s21_src = {"sugoma", "BAOBAB", "yeet"};
  std::list<std::string> std_dest;
  std::list<std::string> std_src = {"sugoma", "BAOBAB", "yeet"};
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(EqualLists(s21_dest, std_dest));
  EXPECT_TRUE(s21_src.empty() == std_src.empty());
}

TEST(ListModifiersMerge, SourceListEmptyCorrectInt) {
  s21::list<int> dest = {1, 2};
  s21::list<int> src;
  s21::list<int> compare(dest);
  dest.merge(src);
  EXPECT_TRUE(EqualLists(dest, compare));
  EXPECT_TRUE(src.empty());
}

TEST(ListModifiersMerge, SourceListEmptyCorrectChar) {
  s21::list<char> dest = {'A', 'B'};
  s21::list<char> src;
  s21::list<char> compare(dest);
  dest.merge(src);
  EXPECT_TRUE(EqualLists(dest, compare));
  EXPECT_TRUE(src.empty());
}

TEST(ListModifiersMerge, SourceListEmptyCorrectStr) {
  s21::list<std::string> dest = {"sus", "amogus"};
  s21::list<std::string> src;
  s21::list<std::string> compare(dest);
  dest.merge(src);
  EXPECT_TRUE(EqualLists(dest, compare));
  EXPECT_TRUE(src.empty());
}

TEST(ListModifiersMerge, SourceListEmptyCompareInt) {
  s21::list<int> s21_dest = {30, 20, 10};
  s21::list<int> s21_src;
  std::list<int> std_dest = {30, 20, 10};
  std::list<int> std_src;
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(EqualLists(s21_dest, std_dest));
  EXPECT_TRUE(s21_src.empty() == std_src.empty());
}

TEST(ListModifiersMerge, SourceListEmptyCompareChar) {
  s21::list<char> s21_dest = {'Z', 'Y', 'X'};
  s21::list<char> s21_src;
  std::list<char> std_dest = {'Z', 'Y', 'X'};
  std::list<char> std_src;
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(EqualLists(s21_dest, std_dest));
  EXPECT_TRUE(s21_src.empty() == std_src.empty());
}

TEST(ListModifiersMerge, SourceListEmptyCompareStr) {
  s21::list<std::string> s21_dest = {"sugoma", "BAOBAB", "yeet"};
  s21::list<std::string> s21_src;
  std::list<std::string> std_dest = {"sugoma", "BAOBAB", "yeet"};
  std::list<std::string> std_src;
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(EqualLists(s21_dest, std_dest));
  EXPECT_TRUE(s21_src.empty() == std_src.empty());
}

TEST(ListModifiersMerge, EmptyListsCorrectInt) {
  s21::list<int> dest;
  s21::list<int> src;
  dest.merge(src);
  EXPECT_TRUE(dest.empty() == src.empty());
}

TEST(ListModifiersMerge, EmptyListsCorrectChar) {
  s21::list<char> dest;
  s21::list<char> src;
  dest.merge(src);
  EXPECT_TRUE(dest.empty() == src.empty());
}

TEST(ListModifiersMerge, EmptyListsCorrectStr) {
  s21::list<std::string> dest;
  s21::list<std::string> src;
  dest.merge(src);
  EXPECT_TRUE(dest.empty() == src.empty());
}

TEST(ListModifiersMerge, EmptyListsCompareInt) {
  s21::list<int> s21_dest;
  s21::list<int> s21_src;
  s21::list<int> std_dest;
  s21::list<int> std_src;
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(s21_dest.empty() == std_dest.empty());
  EXPECT_TRUE(s21_src.empty() == std_src.empty());
}

TEST(ListModifiersMerge, EmptyListsCompareChar) {
  s21::list<char> s21_dest;
  s21::list<char> s21_src;
  s21::list<char> std_dest;
  s21::list<char> std_src;
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(s21_dest.empty() == std_dest.empty());
  EXPECT_TRUE(s21_src.empty() == std_src.empty());
}

TEST(ListModifiersMerge, EmptyListsCompareStr) {
  s21::list<std::string> s21_dest;
  s21::list<std::string> s21_src;
  s21::list<std::string> std_dest;
  s21::list<std::string> std_src;
  s21_dest.merge(s21_src);
  std_dest.merge(std_src);
  EXPECT_TRUE(s21_dest.empty() == std_dest.empty());
  EXPECT_TRUE(s21_src.empty() == std_src.empty());
}
