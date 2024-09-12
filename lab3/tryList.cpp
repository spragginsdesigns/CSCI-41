#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
  // Create a list that holds strings
  list<string> animals;

  // Push "cat" onto the end of the list
  animals.push_back("cat");

  // Push "dog" onto the front of the list
  animals.push_front("dog");

  // Push "bird" onto the end of the list
  animals.push_back("bird");

  // Push "horse" onto the front of the list
  animals.push_front("horse");

  // Print the size of the list
  cout << animals.size() << endl;

  // Iterate through the list from beginning to end and print out each element's value
  for (const auto& animal : animals) {
    cout << animal << endl;
  }

  return 0;
}
