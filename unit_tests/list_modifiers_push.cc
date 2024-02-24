#include "unit_tests.h"

TEST(ListModifiersPush, PushBackSizeCorrectInt) {
  s21::list<int> test;
  s21::list<int> compare{0, 1};
  test.push_back(0);
  test.push_back(1);
  EXPECT_TRUE(test.size() == 2);
  EXPECT_TRUE(EqualLists(test, compare));
}

TEST(ListModifiersPush, PushBackSizeCorrectChar) {
  s21::list<char> test;
  s21::list<char> compare{'a', 'z'};
  test.push_back('a');
  test.push_back('z');
  EXPECT_TRUE(test.size() == 2);
  EXPECT_TRUE(EqualLists(test, compare));
}

TEST(ListModifiersPush, PushBackSizeCorrectStr) {
  s21::list<std::string> test;
  s21::list<std::string> compare{"sussy baka", "amogus"};
  test.push_back("sussy baka");
  test.push_back("amogus");
  EXPECT_TRUE(test.size() == 2);
  EXPECT_TRUE(EqualLists(test, compare));
}

TEST(ListModifiersPush, PushFrontSizeCorrectInt) {
  s21::list<int> test;
  s21::list<int> compare{1, 0};
  test.push_front(0);
  test.push_front(1);
  EXPECT_TRUE(test.size() == 2);
  EXPECT_TRUE(EqualLists(test, compare));
}

TEST(ListModifiersPush, PushFrontSizeCorrectChar) {
  s21::list<char> test;
  s21::list<char> compare{'z', 'a'};
  test.push_front('a');
  test.push_front('z');
  EXPECT_TRUE(test.size() == 2);
  EXPECT_TRUE(EqualLists(test, compare));
}

TEST(ListModifiersPush, PushFrontSizeCorrectStr) {
  s21::list<std::string> test;
  s21::list<std::string> compare{"IMPOSTER", "among us"};
  test.push_front("among us");
  test.push_front("IMPOSTER");
  EXPECT_TRUE(test.size() == 2);
  EXPECT_TRUE(EqualLists(test, compare));
}

TEST(ListModifiersPush, PushBackCompareInt) {
  s21::list<int> s21_test;
  std::list<int> std_test;
  s21_test.push_back(0);
  std_test.push_back(0);
  EXPECT_TRUE(EqualLists(s21_test, std_test));
  s21_test.push_back(1);
  std_test.push_back(1);
  EXPECT_TRUE(EqualLists(s21_test, std_test));
  s21_test.push_back(2);
  std_test.push_back(2);
  EXPECT_TRUE(EqualLists(s21_test, std_test));
}

TEST(ListModifiersPush, PushBackCompareChar) {
  s21::list<char> s21_test;
  std::list<char> std_test;
  s21_test.push_back('a');
  std_test.push_back('a');
  EXPECT_TRUE(EqualLists(s21_test, std_test));
  s21_test.push_back('F');
  std_test.push_back('F');
  EXPECT_TRUE(EqualLists(s21_test, std_test));
  s21_test.push_back('z');
  std_test.push_back('z');
  EXPECT_TRUE(EqualLists(s21_test, std_test));
}

TEST(ListModifiersPush, PushBackCompareStr) {
  s21::list<std::string> s21_test;
  std::list<std::string> std_test;
  s21_test.push_back("aboba");
  std_test.push_back("aboba");
  EXPECT_TRUE(EqualLists(s21_test, std_test));
  s21_test.push_back("LUPA");
  std_test.push_back("LUPA");
  EXPECT_TRUE(EqualLists(s21_test, std_test));
  s21_test.push_back("Pupa");
  std_test.push_back("Pupa");
  EXPECT_TRUE(EqualLists(s21_test, std_test));
}

TEST(ListModifiersPush, PushFrontCompareInt) {
  s21::list<int> s21_test;
  std::list<int> std_test;
  s21_test.push_front(0);
  std_test.push_front(0);
  EXPECT_TRUE(EqualLists(s21_test, std_test));
  s21_test.push_front(1);
  std_test.push_front(1);
  EXPECT_TRUE(EqualLists(s21_test, std_test));
  s21_test.push_front(2);
  std_test.push_front(2);
  EXPECT_TRUE(EqualLists(s21_test, std_test));
}

TEST(ListModifiersPush, PushFrontCompareChar) {
  s21::list<char> s21_test;
  std::list<char> std_test;
  s21_test.push_front('a');
  std_test.push_front('a');
  EXPECT_TRUE(EqualLists(s21_test, std_test));
  s21_test.push_front('F');
  std_test.push_front('F');
  EXPECT_TRUE(EqualLists(s21_test, std_test));
  s21_test.push_front('z');
  std_test.push_front('z');
  EXPECT_TRUE(EqualLists(s21_test, std_test));
}

TEST(ListModifiersPush, PushFrontCompareStr) {
  s21::list<std::string> s21_test;
  std::list<std::string> std_test;
  s21_test.push_front("LOL");
  std_test.push_front("LOL");
  EXPECT_TRUE(EqualLists(s21_test, std_test));
  s21_test.push_front("kek");
  std_test.push_front("kek");
  EXPECT_TRUE(EqualLists(s21_test, std_test));
  s21_test.push_front("Chebureck");
  std_test.push_front("Chebureck");
  EXPECT_TRUE(EqualLists(s21_test, std_test));
}
