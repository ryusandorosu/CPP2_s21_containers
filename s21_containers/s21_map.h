#ifndef SRC_S21_CONTAINERS_S21_MAP_H_
#define SRC_S21_CONTAINERS_S21_MAP_H_

#include <memory>
#include <vector>

#include "tree.h"

namespace s21 {

template <class Key, class T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;

  using size_type = size_t;
  using iterator = typename AvlTree<Key, value_type>::iterator;
  using const_iterator = typename AvlTree<Key, value_type>::const_iterator;

  map() : tree_() {}

  map(std::initializer_list<value_type> const &items) {
    for (auto element : items) {
      tree_.Insert(element);
    }
  }

  map(const map &m) : tree_(m.tree_) {}

  map(map &&m) : tree_(std::move(m.tree_)) {}

  ~map() {}

  map &operator=(map &&m) {
    tree_ = std::move(m.tree_);
    return *this;
  }

  T &at(const Key &key) { return FindOrAdd(key, true); }

  T &operator[](const Key &key) { return FindOrAdd(key, false); }

  iterator begin() const noexcept { return tree_.begin(); }

  iterator end() const noexcept { return tree_.end(); }

  bool empty() const noexcept { return tree_.empty(); }

  size_type size() const noexcept { return tree_.size(); }

  size_type max_size() const noexcept { return tree_.max_size(); }

  void clear() noexcept { tree_.clear(); }

  std::pair<iterator, bool> insert(const value_type &value) {
    return tree_.InsertBool(value);
  }

  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj) {
    std::pair<Key, T> obj_transform = {key, obj};
    return tree_.InsertOrAssign(obj_transform);
  }

  void erase(iterator pos) { tree_.erase(pos); }

  void swap(map &other) { tree_.swap(other.tree_); }

  void merge(map &other) { tree_.merge(other.tree_); }

  bool contains(const Key &key) {
    iterator node = tree_.FindNum(key);
    iterator null;
    return node != null;
  }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> vec;
    for (const auto &arg : {args...}) {
      vec.push_back(insert(arg));
    }
    return vec;
  }

  T &FindOrAdd(const Key &key, bool not_found) {
    iterator it = tree_.Find(key);
    if (it != end()) {
      return (*it).second;
    } else {
      if (not_found) {
        throw std::out_of_range("Container does not have an element");
      } else {
        std::pair<Key, T> new_pair = {key, T()};
        insert(new_pair);
        return (*tree_.Find(key)).second;
      }
    }
  }

 private:
  AvlTree<Key, value_type> tree_;
};

}  // namespace s21

#endif  // SRC_S21_CONTAINERS_S21_MAP_H_
