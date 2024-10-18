#include <string>
#include "testing.h"
#include "hashMap.h"
using namespace std;

void hashMapTest1();
void hashMapTest2();
void hashMapTest3();
void hashMapTest4();

int main() {
  hashMapTest1();
  hashMapTest2();
  hashMapTest3();
  hashMapTest4();

  return 0;
}

void hashMapTest1() {
  HashMap<int, double> table(5);
  bool is_correct = true;

  table.insert(5, 3.14);
  table.insert(6, 5.67);
  if (table.search(5) == nullptr || *table.search(5) != 3.14) is_correct = false;
  if (table.search(6) == nullptr || *table.search(6) != 5.67) is_correct = false;
  if (table.search(10) != nullptr) is_correct = false;

  assertTrue(is_correct, "HashMap<int, double> test");
}

void hashMapTest2() {
  // make sure all the proper hash functions got made
  HashMap<int, int> tInt(42);
  HashMap<char, int> tChar(42);
  HashMap<double, int> tDouble(42);
  HashMap<string, int> tString(42);

  bool is_correct = true;

  // ensure that there will be collisions
  for (int i = 0; i < 128; i++) {
    tInt.insert(i, i+1);
    tChar.insert(static_cast<char>(i), i+1);
    tDouble.insert(static_cast<double>(i), i+1);
    tString.insert(to_string(i), i+1);
  }

  // search for what we inserted
  for (int i = 0; i < 128; i++) {
    if (tInt.search(i) == nullptr || *tInt.search(i) != i+1) is_correct = false;
    if (tChar.search(static_cast<char>(i)) == nullptr || *tChar.search(static_cast<char>(i)) != i+1) is_correct = false;
    if (tDouble.search(static_cast<double>(i)) == nullptr || *tDouble.search(static_cast<double>(i)) != i+1) is_correct = false;
    if (tString.search(to_string(i)) == nullptr || *tString.search(to_string(i)) != i+1) is_correct = false;
  }

  assertTrue(is_correct, "HashMap comprehensive test");
}

void hashMapTest3() {
  HashMap<string, int> table(10);
  bool is_correct = true;

  table.insert("apple", 1);
  table.insert("banana", 2);
  table.insert("cherry", 3);

  if (table.search("apple") == nullptr || *table.search("apple") != 1) is_correct = false;
  if (table.search("banana") == nullptr || *table.search("banana") != 2) is_correct = false;
  if (table.search("cherry") == nullptr || *table.search("cherry") != 3) is_correct = false;
  if (table.search("date") != nullptr) is_correct = false;

  assertTrue(is_correct, "HashMap<string, int> test");
}

void hashMapTest4() {
  HashMap<double, string> table(7);
  bool is_correct = true;

  table.insert(3.14, "pi");
  table.insert(2.71, "e");
  table.insert(1.41, "sqrt(2)");

  if (table.search(3.14) == nullptr || *table.search(3.14) != "pi") is_correct = false;
  if (table.search(2.71) == nullptr || *table.search(2.71) != "e") is_correct = false;
  if (table.search(1.41) == nullptr || *table.search(1.41) != "sqrt(2)") is_correct = false;
  if (table.search(1.0) != nullptr) is_correct = false;

  // Test updating an existing key
  table.insert(3.14, "PI");
  if (table.search(3.14) == nullptr || *table.search(3.14) != "PI") is_correct = false;

  assertTrue(is_correct, "HashMap<double, string> test with update");
}
