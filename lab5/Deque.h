#ifndef DEQUE_H
#define DEQUE_H

#include <list>
#include <stdexcept>

// a deque using a std::list

template <class T>
class Deque {
public:
  void push_front(const T& item) {
    l.push_front(item);
  }

  void push_back(const T& item) {
    l.push_back(item);
  }

  void pop_front() {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }
    l.pop_front();
  }

  void pop_back() {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }
    l.pop_back();
  }

  T& peek_front() {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }
    return l.front();
  }

  T& peek_back() {
    if (empty()) {
      throw std::out_of_range("Deque is empty");
    }
    return l.back();
  }

  bool empty() const {
    return l.empty();
  }

  int size() const {
    return static_cast<int>(l.size());
  }

private:
  std::list<T> l;
};

#endif /* DEQUE_H */
