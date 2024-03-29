#include "s21_vector.h"

namespace s21 {
// default constructor
template <typename value_type>
Vector<value_type>::Vector() : arr_(nullptr), sz_(0), cap_(0) {}

// destructor
template <typename value_type>
Vector<value_type>::~Vector() {
  sz_ = 0;
  cap_ = 0;
  delete[] arr_;
  arr_ = nullptr;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector &&v) {
  if (this != &v) {
    delete[] arr_;
    arr_ = v.arr_;
    sz_ = v.sz_;
    cap_ = v.cap_;
    v.arr_ = nullptr;
    v.sz_ = 0;
    v.cap_ = 0;
  }
  return *this;
}

template <typename value_type>
Vector<value_type> &Vector<value_type>::operator=(const Vector &other) {
  if (this != &other) {
    delete[] arr_;
    sz_ = other.sz_;
    cap_ = other.cap_;

    arr_ = new value_type[cap_];
    std::copy(other.arr_, other.arr_ + sz_, arr_);
  }
  return *this;
}
// constructor with 1 parametrs
template <typename value_type>
Vector<value_type>::Vector(size_type n)
    : arr_(new value_type[n]{}), sz_(n), cap_(n) {}

// initializer list constructor, creates vector initizialized using
// std::initializer_list
template <typename value_type>
Vector<value_type>::Vector(std::initializer_list<value_type> const &items) {
  sz_ = cap_ = items.size();
  arr_ = new value_type[cap_];
  std::copy(items.begin(), items.end(), arr_);
}

template <typename value_type>
Vector<value_type>::Vector(const Vector &v)
    : arr_(new value_type[v.cap_]), sz_(v.sz_), cap_(v.cap_) {
  std::copy(v.arr_, v.arr_ + v.sz_, arr_);
}

template <typename value_type>
Vector<value_type>::Vector(Vector &&v)
    : arr_(v.arr_), sz_(v.sz_), cap_(v.cap_) {
  v.arr_ = nullptr;
  v.sz_ = v.cap_ = 0;
}

template <typename value_type>
bool Vector<value_type>::empty() {
  return sz_ == 0;
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::size() {
  return sz_;
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::max_size() {
  return std::numeric_limits<value_type>::max();
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::capacity() {
  return cap_;
}

template <typename value_type>
void Vector<value_type>::clear() {
  delete[] arr_;
  arr_ = nullptr;
  sz_ = 0;
  cap_ = 0;
}

template <typename value_type>
void Vector<value_type>::swap(Vector &other) {
  std::swap(arr_, other.arr_);
  std::swap(sz_, other.sz_);
  std::swap(cap_, other.cap);
}

// уменьшает использ памяти за счет уменьшения неиспольз памяти
template <typename value_type>
void Vector<value_type>::shrink_to_fit() {
  if (sz_ == 0) {
    sz_ = 0;
    delete[] arr_;
    arr_ = nullptr;
    return;
  }
  if (sz_ < cap_) {
    value_type *new_arr = new value_type[sz_];
    std::copy(arr_, arr_ + sz_, new_arr);
    delete[] arr_;
  }
  if (sz_ == cap_) return;
}

template <typename value_type>
void Vector<value_type>::reserve(size_type new_capacity) {
  if (new_capacity <= cap_) {
    return;
  }
  value_type *new_arr = new value_type[new_capacity];
  std::copy(arr_, arr_ + sz_, new_arr);
  delete[] arr_;
  arr_ = new_arr;
  cap_ = new_capacity;
};

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::at(size_type pos) {
  if (pos < size()) {
    return arr_[pos];
  } else {
    throw std::out_of_range("out of Vector");
  }
}

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::operator[](
    size_type pos) {
  return arr_[pos];
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::front() const {
  if (sz_ == 0) {
    throw std::out_of_range("empty Vector");
    // return;
  }
  return arr_[0];
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::back() const {
  if (sz_ == 0) {
    throw std::out_of_range("empty Vector");
    // return;
  }
  return arr_[sz_ - 1];
}

template <typename T>
T *s21::Vector<T>::data() {
  return arr_;
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::begin() {
  return arr_;
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::end() {
  return arr_ + sz_;
}

template <typename value_type>
void Vector<value_type>::pop_back() {
  if (sz_ > 0) {
    sz_--;
  }
}

template <typename value_type>
void Vector<value_type>::erase(iterator pos) {
  if (pos >= end()) {
    return;
  }
  for (auto it = pos + 1; it != end(); ++it, ++pos) {
    *pos = std::move(*it);
  }
  --sz_;
}

template <typename value_type>
void Vector<value_type>::push_back(const_reference value) {
  if (sz_ >= cap_) {
    if (cap_ == 0) {
      reserve(1);
    } else {
      // reserve(cap_ * 2);
      size_type new_capacity = cap_ * 2;
      value_type *new_arr = new value_type[new_capacity];
      std::copy(arr_, arr_ + sz_, new_arr);
      delete[] arr_;
      arr_ = new_arr;
      cap_ = new_capacity;
    }
  }
  arr_[sz_] = value;
  ++sz_;
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::insert(
    iterator pos, const_reference value) {
  size_type index = pos - begin();
  if (sz_ >= cap_) {
    if (cap_ == 0) {
      reserve(1);
    } else {
      reserve(cap_ * 2);
    }
  }

  for (size_type i = sz_; i > index; --i) {
    arr_[i] = std::move(arr_[i - 1]);
  }

  arr_[index] = value;
  ++sz_;
  return begin() + index;
}

template <typename value_type>
template <typename... Args>
// appends new elements to the end of the container
void Vector<value_type>::insert_many_back(Args &&...args) {
  (push_back(std::forward<Args>(args)), ...);
}

template <typename value_type>
template <typename... Args>
// inserts new elements into the container directly before pos
typename Vector<value_type>::iterator Vector<value_type>::insert_many(
    const_iterator pos, Args &&...args) {
  auto indx = pos - arr_.begin();
  arr_.reserve(arr_.size() + sizeof...(args));
  auto it = arr_.begin() + indx;
  ((it = arr_.insert(it, std::forward<Args>(args))), ...);
  return it;
}
}  // namespace s21