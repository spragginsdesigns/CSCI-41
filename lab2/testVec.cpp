#include <iostream>
#include "vec.h"
#include "testing.h"
using namespace std;

void testVecCopyConstructor();
void testVecCopyAssignment();
void testVecDestructor();
void testVecCopyConstructorWithLargeVector();
void testVecCopyAssignmentWithEmptyVector();
void testVecMultipleCopies();

int main() {
  testVecCopyConstructor();
  testVecCopyAssignment();
  testVecDestructor();
  testVecCopyConstructorWithLargeVector();
  testVecCopyAssignmentWithEmptyVector();
  testVecMultipleCopies();

  return 0;
}

void testVecCopyConstructor() {
  Vec v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  Vec v2(v1);
  v1.push_back(4);
  v1.push_back(5);
  v2.push_back(-4);
  v2.push_back(-5);

  assertTrue(v1.at(0) == v2.at(0) &&
             v1.at(1) == v2.at(1) &&
             v1.at(2) == v2.at(2) &&
             v1.at(3) == 4 &&
             v2.at(3) == -4 &&
             v1.at(4) == 5 &&
             v2.at(4) == -5,
             "copy constructor");
}

void testVecCopyAssignment() {
  Vec v1, v2;
  v1.push_back(1);
  v1.push_back(2);
  v2.push_back(3);
  v2.push_back(4);

  v2 = v1;

  v2.push_back(5);
  v1.push_back(3);

  assertTrue(v2.at(0) == 1 &&
             v2.at(1) == 2 &&
             v2.at(2) == 5 &&
             v1.at(0) == 1 &&
             v1.at(1) == 2 &&
             v1.at(2) == 3 &&
             v2.size() == 3 &&
             v1.size() == 3,
             "copy assignment operator");
}

void testVecDestructor() {
  Vec* v = new Vec();
  v->push_back(1);
  v->push_back(2);
  v->push_back(3);
  delete v;
  // If the destructor works correctly, this test shouldn't cause a memory leak
  assertTrue(true, "destructor (no crash)");
}

void testVecCopyConstructorWithLargeVector() {
  Vec v1;
  for (int i = 0; i < 1000; ++i) {
    v1.push_back(i);
  }
  Vec v2(v1);

  bool allEqual = true;
  for (int i = 0; i < 1000; ++i) {
    if (v1.at(i) != v2.at(i)) {
      allEqual = false;
      break;
    }
  }

  assertTrue(allEqual && v1.size() == v2.size(), "copy constructor with large vector");
}

void testVecCopyAssignmentWithEmptyVector() {
  Vec v1, v2;
  v1.push_back(1);
  v1.push_back(2);

  v1 = v2;

  assertTrue(v1.size() == 0, "copy assignment with empty vector");
}

void testVecMultipleCopies() {
  Vec v1;
  v1.push_back(1);
  v1.push_back(2);

  Vec v2 = v1;
  Vec v3 = v2;
  Vec v4;
  v4 = v3;

  v1.push_back(3);
  v2.push_back(4);
  v3.push_back(5);
  v4.push_back(6);

  assertTrue(v1.size() == 3 && v2.size() == 3 && v3.size() == 3 && v4.size() == 3 &&
             v1.at(2) == 3 && v2.at(2) == 4 && v3.at(2) == 5 && v4.at(2) == 6,
             "multiple copies");
}
