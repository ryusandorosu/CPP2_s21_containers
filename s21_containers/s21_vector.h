#ifndef SRC_S21_CONTAINERS_S21_VECTOR_H
#define SRC_S21_CONTAINERS_S21_VECTOR_H

// #include <iostream>
#include <stdexcept>

namespace s21 {
template <typename T>
class Vector {
 public:
  // Vector Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Vector Member functions
  Vector();
  Vector(size_type n);
  Vector(std::initializer_list<value_type> const &items);
  Vector(const Vector &v);
  Vector(Vector &&v);
  ~Vector();
  Vector &operator=(Vector &&v);
  Vector &operator=(const Vector &other);

  // Vector Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front() const;
  const_reference back() const;
  T *data();

  // Vector Iterators
  iterator begin();
  iterator end();

  // Vector Capacity
  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type new_capacity);
  size_type capacity();
  void shrink_to_fit();

  // Vector Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(Vector &other);

  // Bonus
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);

  reference operator++() { return *(++arr_); }
  reference operator--() { return *(--arr_); }
  const_reference operator++(int) { return *(arr_++); }
  const_reference operator--(int) { return *(arr_--); }
  const_reference operator+(int a) { return *(arr_ + a); }
  const_reference operator-(int a) { return *(arr_ - a); }
  bool operator==(const iterator &iter) { return arr_ == iter; }
  bool operator!=(const iterator &iter) { return arr_ != iter; }

 private:
  value_type *arr_;
  size_t sz_;
  size_t cap_;
};

}  // namespace s21
#include "vector.tpp"
#endif  // SRC_S21_CONTAINERS_S21_VECTOR_H
