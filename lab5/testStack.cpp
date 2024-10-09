#include <iostream>
#include "Stack.h"
#include "testing.h"
using namespace std;

void testStack1();
void testStack2();
void testStack3();

int main() {
  testStack1();
  testStack2();
  testStack3();

  return 0;
}

void testStack1() {
  // Existing test case
}

void testStack2() {
  Stack<string> s;
  bool is_correct = true;

  s.push("hello");
  s.push("world");
  if (s.size() != 2) is_correct = false;
  if (s.peek() != "world") is_correct = false;
  if (s.pop() != "world") is_correct = false;
  if (s.peek() != "hello") is_correct = false;
  if (s.size() != 1) is_correct = false;
  s.pop();
  if (!s.empty()) is_correct = false;

  assertTrue(is_correct, "Stack<string> operations");
}

void testStack3() {
  Stack<double> s;
  bool is_correct = true;

  try {
    s.pop();
    is_correct = false;  // Should have thrown an exception
  } catch (const std::out_of_range&) {
    // Expected behavior
  }

  s.push(3.14);
  s.push(2.71);
  if (s.size() != 2) is_correct = false;
  if (s.peek() != 2.71) is_correct = false;
  if (s.pop() != 2.71) is_correct = false;
  if (s.peek() != 3.14) is_correct = false;

  assertTrue(is_correct, "Stack<double> operations and exception handling");
}
