#include "list.h"
#include "testing.h"

void test_push_front();
void test_push_back();
void test_pop_front();
void test_pop_back();
void test_copy_constructor();
void test_copy_assignment();

int main() {
  test_push_front();
  test_push_back();
  test_pop_front();
  test_pop_back();
  test_copy_constructor();
  test_copy_assignment();

  return 0;
}

// Caveat: size() needs to be correct before these tests pass

void test_push_front() {
  List l;
  bool is_correct = true;

  if (l.size() != 0) is_correct = false;

  l.push_front({2, 2});
  if (l.size() != 1) is_correct = false;
  if (l.getFirst()->data.getX() != 2) is_correct = false;

  l.push_front({3, 4});
  if (l.size() != 2) is_correct = false;
  if (l.getFirst()->data.getY() != 4) is_correct = false;

  l.push_front({5, 6});
  if (l.size() != 3) is_correct = false;
  if (l.getFirst()->data.getX() != 5) is_correct = false;

  assertTrue(is_correct, "push_front");
}

void test_push_back() {
  List l;
  bool is_correct = true;

  if (l.size() != 0) is_correct = false;

  l.push_back({2, 2});
  if (l.size() != 1) is_correct = false;
  if (l.getLast()->data.getX() != 2) is_correct = false;

  l.push_back({3, 4});
  if (l.size() != 2) is_correct = false;
  if (l.getLast()->data.getY() != 4) is_correct = false;

  l.push_back({5, 6});
  if (l.size() != 3) is_correct = false;
  if (l.getLast()->data.getX() != 5) is_correct = false;

  assertTrue(is_correct, "push_back");
}

void test_pop_front() {
  List l;
  bool is_correct = true;

  l.push_back({2, 2});
  l.push_back({3, 4});

  l.pop_front();
  if (l.size() != 1) is_correct = false;
  if (l.getFirst()->data.getX() != 3) is_correct = false;
  if (l.getLast()->data.getX() != 3) is_correct = false;
  l.pop_front();
  if (l.size() != 0) is_correct = false;

  assertTrue(is_correct, "pop_front");
}

void test_pop_back() {
  List l;
  bool is_correct = true;

  l.push_back({2, 2});
  l.push_back({3, 4});

  l.pop_back();
  if (l.size() != 1) is_correct = false;
  if (l.getFirst()->data.getX() != 2) is_correct = false;
  if (l.getLast()->data.getX() != 2) is_correct = false;
  l.pop_back();
  if (l.size() != 0) is_correct = false;

  assertTrue(is_correct, "pop_back");
}

void test_copy_constructor() {
  List l;
  bool is_correct = true;

  l.push_back({2, 2});
  l.push_back({3, 4});

  List l2(l);
  if (l2.size() != 2) is_correct = false;
  if (l.getFirst() == l2.getFirst()) is_correct = false;
  if (l.getFirst()->next == l2.getFirst()->next) is_correct = false;

  assertTrue(is_correct, "copy constructor");
}

void test_copy_assignment() {
  List l;
  bool is_correct = true;

  l.push_back({2, 2});
  l.push_back({3, 4});

  List l2;
  l2.push_back({5, 6});
  l2.push_back({7, 8});
  l2.push_back({7, 6});
  l2.push_back({8, 8});

  l = l;
  l2 = l;
  l2 = l2;

  if (l2.size() != 2) is_correct = false;
  if (l.getFirst() == l2.getFirst()) is_correct = false;
  if (l.getFirst()->next == l2.getFirst()->next) is_correct = false;

  assertTrue(is_correct, "copy assignment");
}
