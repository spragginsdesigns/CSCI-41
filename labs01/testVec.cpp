#include <iostream>
#include "vec.h"
#include "testing.h"
using namespace std;

void testVec1();
void testVec2();
void testVec3();
void testVec4();
void testVec5();
void testVec6();
void testVec7();
void testVec8();
void testVec9();

int main() {
  testVec1();
  testVec2();
  testVec3();
  testVec4();
  // Add four more tests that call assertTrue EXACTLY 4 more times
  testVec5();
  testVec6();
  testVec7();
  testVec8();
  testVec9();
  return 0;
}

void testVec1() {
  Vec v;
  assertTrue(v.size() == 0, "empty Vec");
}

void testVec2() {
  Vec v;
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  assertTrue(v.size() == 3 &&
             v.at(0) == 3 &&
             v.at(1) == 2 &&
             v.at(2) == 1,
             "Vec {3, 2, 1}");
}

void testVec3() {
  Vec v;
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  v.sort();
  assertTrue(v.size() == 3 &&
             v.at(0) == 1 &&
             v.at(1) == 2 &&
             v.at(2) == 3,
             "Sorting Vec {3, 2, 1}");
}

void testVec4() {
  Vec v;

  // insert 32 to 0
  for (int i = 32; i >= 0; i--) {
    v.push_back(i);
  }

  // sort
  v.sort();

  // check correctly sorted and that all the elements exist where they
  // should
  bool is_correct = true;
  if (v.size() != 33)
    is_correct = false;
  for (int i = 0; i <= 32; i++) {
    if (v.at(i) != i)
      is_correct = false;
  }

  // check modifiability using .at()
  v.at(2)++;
  if (v.at(2) != 3)
    is_correct = false;

  assertTrue(is_correct, "comprehensive large Vec test");
}

void testVec5() {
  Vec v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
  }
  assertTrue(v.size() == 10 && v.at(9) == 9, "Vec with 10 elements");
}

  void testVec6() {
  Vec v;
  v.push_back(5);
  v.push_back(5);
  v.push_back(5);
  assertTrue(v.size() == 3 && v.at(0) == 5 && v.at(1) == 5 && v.at(2) == 5, "Vec with duplicate elements");
}

void testVec7() {
  Vec v;
  v.push_back(100);
  v.at(0) = 200;
  assertTrue(v.size() == 1 && v.at(0) == 200, "Vec element modification");
}

void testVec8() {
    Vec v;
    for (int i = 0; i < 5; i++) {
        v.push_back(5 - i);
    }
    assertTrue(v.size() == 5 && v.at(0) == 5 && v.at(4) == 1, "Vec with 5 elements in descending order");
}

void testVec9() {
    Vec v;
    for (int i = 0; i < 5; i++) {
        v.push_back(5 - i);
    }
    v.sort();
    assertTrue(v.at(0) == 1 && v.at(4) == 5, "Sorting small Vec");
}