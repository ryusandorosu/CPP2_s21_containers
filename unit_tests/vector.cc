#include "unit_tests.h"

using namespace s21;
// конструктор по умолчанию
TEST(VectorTest, DefaultConstructor) {
  s21::Vector<int> var;
  ASSERT_EQ(var.size(), 0);
  ASSERT_EQ(var.capacity(), 0);
  ASSERT_TRUE(var.empty());
}

// конструктор с одним параметром
TEST(VectorTest, SingleParameterConstructor) {
  s21::Vector<int> v(5);
  ASSERT_EQ(v.size(), 5);
  ASSERT_EQ(v.capacity(), 5);
  ASSERT_FALSE(v.empty());
}

// конструктор со списком инициализации
TEST(VectorTest, InitializerListConstructor) {
  s21::Vector<int> v{1, 2, 3, 4, 5};
  ASSERT_EQ(v.size(), 5);
  ASSERT_EQ(v.capacity(), 5);
  ASSERT_FALSE(v.empty());
  for (int i = 0; i < 5; ++i) {
    ASSERT_EQ(v[i], i + 1);
  }
}

// Конструктор копирования
TEST(VectorTest, CopyConstructor) {
  s21::Vector<int> v1{1, 2, 3, 4, 5};
  s21::Vector<int> v2 = v1;
  ASSERT_EQ(v2.size(), v1.size());
  ASSERT_EQ(v2.capacity(), v1.capacity());
  for (s21::Vector<int>::size_type i = 0; i < v1.size(); ++i) {
    ASSERT_EQ(v2[i], v1[i]);
  }
}

// Тестирование перемещающего конструктора
TEST(VectorTest, MoveConstructor) {
  s21::Vector<int> v1{1, 2, 3, 4, 5};
  s21::Vector<int> v2 = std::move(v1);
  ASSERT_EQ(v1.size(), 0);
  ASSERT_EQ(v2.size(), 5);
  ASSERT_EQ(v2.capacity(), 5);
  for (int i = 0; i < 5; ++i) {
    ASSERT_EQ(v2[i], i + 1);
  }
}

// clear
TEST(VectorTest, ClearMethod) {
  s21::Vector<int> v{1, 2, 3, 4, 5};
  v.clear();
  ASSERT_EQ(v.size(), 0);
  ASSERT_EQ(v.capacity(), 0);
  ASSERT_TRUE(v.empty());
}

TEST(VectorTest, FrontNoneEmpty) {
  s21::Vector<int> teamvector{1, 2, 3};

  ASSERT_NO_THROW({
    const int& frontEl = teamvector.front();
    ASSERT_EQ(frontEl, 1);
  });
}

TEST(VectorTest, Front) {
  std::vector<char> literal{'a', 'b', 'c', 'd', 'e', 'f'};
  s21::Vector<char> lit{'a', 'b', 'c', 'd', 'e', 'f'};

  for (std::size_t i = 0; i < literal.size(); ++i) {
    ASSERT_EQ(literal[i], lit[i]);
  }
}

TEST(VectorTest, ConstructorEmpty) {
  s21::Vector<int> vec;
  ASSERT_TRUE(vec.empty());
  ASSERT_EQ(vec.size(), 0);
}

TEST(VectorTest, ConstructorSize) {
  s21::Vector<int> vec(5);
  ASSERT_FALSE(vec.empty());
  ASSERT_EQ(vec.size(), 5);
}

TEST(VectorTest, InitializerListConstructors) {
  s21::Vector<int> vec{1, 2, 3};
  ASSERT_FALSE(vec.empty());
  ASSERT_EQ(vec.size(), 3);
  ASSERT_EQ(vec[0], 1);
  ASSERT_EQ(vec[1], 2);
  ASSERT_EQ(vec[2], 3);
}

TEST(VectorTest, Front1) {
  s21::Vector<int> vec{1, 2, 3};
  ASSERT_EQ(vec.front(), 1);
}

TEST(VectorTest, Back) {
  s21::Vector<int> vec{1, 2, 3};
  ASSERT_EQ(vec.back(), 3);
}

TEST(VectorTest, At) {
  s21::Vector<int> vec{1, 2, 3};
  // std::Vector<int> vec{1, 2, 3};
  ASSERT_EQ(vec.at(1), 2);
  ASSERT_THROW(vec.at(3), std::out_of_range);
}

TEST(VectorTest, Clear) {
  s21::Vector<int> vec{1, 2, 3};
  vec.clear();
  ASSERT_TRUE(vec.empty());
  ASSERT_EQ(vec.size(), 0);
}

TEST(VectorTest, Reserve) {
  s21::Vector<int> vec;
  vec.reserve(10);
  ASSERT_EQ(vec.capacity(), 10);
}

TEST(VectorTest, FrontEmptyVector) {
  s21::Vector<int> vec;
  ASSERT_THROW(vec.front(), std::out_of_range);
}

TEST(VectorTest, BackEmptyVector) {
  s21::Vector<int> vec;
  ASSERT_THROW(vec.back(), std::out_of_range);
}

TEST(VectorTest, ReserveNoCapacityChange) {
  s21::Vector<int> vec;
  vec.push_back(42);
  vec.reserve(1);
  ASSERT_EQ(vec.capacity(), 1);
}

TEST(VectorTest, ReserveIncreaseCapacity) {
  s21::Vector<int> vec;
  vec.reserve(10);
  ASSERT_EQ(vec.capacity(), 10);
}

TEST(VectorTest, PopBackDecreasesSize) {
  s21::Vector<int> vec{1, 2, 3};
  const auto initial_size = vec.size();
  vec.pop_back();
  EXPECT_EQ(vec.size(), initial_size - 1);
}

TEST(VectorTest, PopBackDoesNothingOnEmptyVector) {
  s21::Vector<int> vec;
  vec.pop_back();
  EXPECT_EQ(vec.size(), 0);
}

TEST(VectorTest, TestStruct) {
  struct test_struct {
    int i = 0;
    double m = 0;
    float n = 0;
  };
  test_struct s1 = {1, 1.9, 1e-8};
  test_struct s2 = {2, 2.9, 1e-9};
  test_struct s3 = {3, 3.9, 1e-10};

  s21::Vector<test_struct> s21_abc;
  std::vector<test_struct> std_abc;
  s21_abc.push_back(s1);
  s21_abc.push_back(s2);
  s21_abc.push_back(s3);

  std_abc.push_back(s1);
  std_abc.push_back(s2);
  std_abc.push_back(s3);

  EXPECT_TRUE(s21_abc.empty() == std_abc.empty());
  EXPECT_TRUE(s21_abc.size() == std_abc.size());
  EXPECT_TRUE(s21_abc.capacity() == std_abc.capacity());

  std::vector<test_struct>::iterator std_itr = std_abc.begin();
  s21::Vector<test_struct>::iterator s21_itr = s21_abc.begin();

  for (; s21_itr != s21_abc.end() && std_itr != std_abc.end();
       ++s21_itr, ++std_itr) {
    EXPECT_TRUE((*s21_itr).i == (*std_itr).i);
    EXPECT_TRUE((*s21_itr).m == (*std_itr).m);
    EXPECT_TRUE((*s21_itr).n == (*std_itr).n);
  }
}

TEST(VectorTest, TestInsert) {
  s21::Vector<int> s21_vec;
  std::vector<int> std_vec;
  s21_vec.push_back(1);
  s21_vec.push_back(2);
  s21_vec.push_back(4);

  std_vec.push_back(1);
  std_vec.push_back(2);
  std_vec.push_back(4);

  // Insert value in the middle of vector
  auto iter = s21_vec.insert(s21_vec.begin() + 2, 3);
  auto std_iter = std_vec.insert(std_vec.begin() + 2, 3);

  EXPECT_EQ(s21_vec.size(), std_vec.size());
  EXPECT_EQ(*iter, *std_iter);
  EXPECT_EQ(s21_vec[2], std_vec[2]);

  // Insert value before the beginning of vector
  iter = s21_vec.insert(s21_vec.begin(), 0);
  std_iter = std_vec.insert(std_vec.begin(), 0);
  EXPECT_EQ(s21_vec.size(), std_vec.size());
  EXPECT_EQ(*iter, *std_iter);
  EXPECT_EQ(s21_vec[0], std_vec[0]);

  // Insert value after the end of vector
  iter = s21_vec.insert(s21_vec.end(), 5);
  std_iter = std_vec.insert(std_vec.end(), 5);

  EXPECT_EQ(s21_vec.size(), std_vec.size());
  EXPECT_EQ(*iter, *std_iter);
  EXPECT_EQ(s21_vec[5], std_vec[5]);
}

TEST(VectorTest, TestErase) {
  s21::Vector<int> s21_abc(1);
  std::vector<int> std_abc(1);
  s21::Vector<int>::iterator s21_iter = s21_abc.begin();
  std::vector<int>::iterator std_iter = std_abc.begin();

  s21_abc.erase(s21_iter);
  std_abc.erase(std_iter);
  EXPECT_TRUE(s21_abc.empty() == std_abc.empty());
}

TEST(VectorTest, EraseReturn) {
  s21::Vector<int> vec = {1, 2, 3, 4, 5};
  auto it = vec.begin() + 5;  //
  vec.erase(it);

  ASSERT_EQ(vec.size(), 5);
  for (size_t i = 0; i < vec.size(); ++i) {
    ASSERT_EQ(vec[i], i + 1);
  }
}

TEST(VectorTest, EraseMoveAssignment) {
  s21::Vector<int> vec = {1, 2, 3, 4, 5};
  auto it = vec.begin() + 2;
  vec.erase(it);

  ASSERT_EQ(vec.size(), 4);
  ASSERT_EQ(vec[0], 1);
  ASSERT_EQ(vec[1], 2);
  ASSERT_EQ(vec[2], 4);
  ASSERT_EQ(vec[3], 5);
}

TEST(VectorTest, InsertReserveOneCheck) {
  s21::Vector<int> vec;
  vec.reserve(5);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  auto it = vec.insert(vec.begin(), 0);

  ASSERT_EQ(vec.size(), 4);
  ASSERT_GE(vec.capacity(), 5);

  ASSERT_EQ(vec[0], 0);
  ASSERT_EQ(vec[1], 1);
  ASSERT_EQ(vec[2], 2);
  ASSERT_EQ(vec[3], 3);

  ASSERT_EQ(*it, 0);
  ASSERT_EQ(it - vec.begin(), 0);
}
