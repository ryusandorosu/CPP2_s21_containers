#include "s21_array.h"

namespace s21 {
template <typename T, size_t S>
Array<T, S>::Array() : data_(S ? new T[S]() : nullptr), size_(S) {}

template <typename T, size_t S>
Array<T, S>::Array(std::initializer_list<T> const &items)
    : data_(new T[items.size()]()), size_(S) {
  if (items.size() > S) {
    delete[] data_;
    throw std::out_of_range(
        "Error, array constructor does not accept a sheet larger than its "
        "size");
  }

  size_t i = 0;
  for (const auto &item : items) {
    this->data_[i++] = item;
  }
}

template <typename T, size_t S>
Array<T, S>::Array(const Array &a) : size_(a.size_), data_(new T[a.size_]) {
  copy(a.data_, a.data_ + a.size_, data_);
}

template <typename T, size_t S>
Array<T, S>::~Array() {
  delete[] data_;
  size_ = 0;
  data_ = nullptr;
}

template <typename T, size_t S>
Array<T, S>::Array(Array &&a) noexcept : size_(a.size_), data_(a.data_) {
  a.size_ = 0;
  a.data_ = nullptr;
}

template <typename T, size_t S>
Array<T, S> &Array<T, S>::operator=(Array<T, S> &&a) {
  if (this != &a) {
    delete[] data_;
    size_ = a.size_;
    data_ = a.data_;
    a.size_ = 0;
    a.data_ = nullptr;
  }
  return *this;
}

template <typename T, size_t S>
Array<T, S> &Array<T, S>::operator=(const Array<T, S> &a) {
  if (this != &a) {
    delete[] data_;
    size_ = a.size_;
    data_ = new T[size_];
    copy(a.data_, a.data_ + a.size_, data_);
  }
  return *this;
}

template <typename T, size_t S>
T &Array<T, S>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

template <typename T, size_t S>
T &Array<T, S>::operator[](size_type pos) {
  if (pos >= S) throw std::out_of_range("Index out of range");
  return data_[pos];
}

template <typename T, size_t S>
const T &Array<T, S>::front() const {
  return data_[0];
}

template <typename T, size_t S>
const T &Array<T, S>::back() const {
  return data_[size_ - 1];
}

template <typename T, size_t S>
T *Array<T, S>::data() {
  return data_;
}

template <typename T, size_t S>
T *Array<T, S>::begin() {
  return data_;
}

template <typename T, size_t S>
T *Array<T, S>::end() {
  return data_ + S;
}

template <typename T, size_t S>
bool Array<T, S>::empty() const noexcept {
  return size_ == 0;
}

template <typename T, size_t S>
size_t Array<T, S>::size() const {
  return S;
}

template <typename T, size_t S>
size_t Array<T, S>::max_size() const {
  return S;
}

template <typename T, size_t S>
void Array<T, S>::swap(Array &other) {
  for (size_t i = 0; i < S; i++) {
    std::swap(data_[i], other.data_[i]);
  }
}

template <typename T, size_t S>
void Array<T, S>::fill(const T &value) {
  std::fill(begin(), end(), value);
}
}  // namespace s21
