#ifndef SRC_S21_CONTAINERS_S21_ARRAY_H_
#define SRC_S21_CONTAINERS_S21_ARRAY_H_

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T, size_t S>
class Array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  Array();
  Array(std::initializer_list<value_type> const &items);
  Array(const Array &a);
  Array(Array &&a) noexcept;
  ~Array();

  Array<T, S> &operator=(Array<T, S> &&a);
  Array<T, S> &operator=(const Array<T, S> &a);

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front() const;
  const_reference back() const;
  iterator data();

  iterator begin();
  iterator end();

  bool empty() const noexcept;
  size_type size() const;
  size_type max_size() const;

  void swap(Array &other);
  void fill(const_reference value);

 private:
  value_type *data_;
  size_type size_ = S;
};
};  // namespace s21
#include "array.tpp"

#endif  // SRC_S21_CONTAINERS_S21_ARRAY_H_
