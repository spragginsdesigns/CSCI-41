#ifndef STACK_H
#define STACK_H

#include "Deque.h"

// we'll make a Stack class using our Deque class

template <class T>
class Stack {
public:
  void push(const T& item) {
    d.push_back(item);
  }

  T pop() {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }
    T item = d.peek_back();
    d.pop_back();
    return item;
  }

  T& peek() {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }
    return d.peek_back();
  }

  bool empty() const {
    return d.empty();
  }

  int size() const {
    return d.size();
  }

private:
  Deque<T> d;
};

// FІХМE: implement the member functions


#endif /* STACK_H */
