#include <iostream>
#include "Deque.h"
#include "testing.h"
using namespace std;

void testDeque1();
void testDeque2();
void testDeque3();

int main() {
  testDeque1();
  testDeque2();
  testDeque3();

  return 0;
}

void testDeque1() {
  Deque<int> d;
  bool is_correct = true;

  if (d.size() != 0) is_correct = false;
  d.push_back(5);
  d.push_front(3);
  if (d.size() != 2) is_correct = false;
  if (d.peek_front() != 3) is_correct = false;
  if (d.peek_back() != 5) is_correct = false;
  d.pop_front();
  d.pop_back();
  if (!d.empty()) is_correct = false;

  assertTrue(is_correct, "general Deque<int> operations");
}

void testDeque2() {
  Deque<string> d;
  bool is_correct = true;

  d.push_back("world");
  d.push_front("hello");
  if (d.size() != 2) is_correct = false;
  if (d.peek_front() != "hello") is_correct = false;
  if (d.peek_back() != "world") is_correct = false;
  d.pop_back();
  if (d.peek_back() != "hello") is_correct = false;
  d.pop_front();
  if (!d.empty()) is_correct = false;

  assertTrue(is_correct, "Deque<string> operations");
}

void testDeque3() {
  Deque<double> d;
  bool is_correct = true;

  try {
    d.pop_front();
    is_correct = false;  // Should have thrown an exception
  } catch (const std::out_of_range&) {
    // Expected behavior
  }

  d.push_back(3.14);
  d.push_front(2.71);
  if (d.size() != 2) is_correct = false;
  if (d.peek_front() != 2.71) is_correct = false;
  if (d.peek_back() != 3.14) is_correct = false;

  assertTrue(is_correct, "Deque<double> operations and exception handling");
}
