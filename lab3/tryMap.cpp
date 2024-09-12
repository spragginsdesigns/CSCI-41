#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  // Create a map that goes from string keys to int values
  map<string, int> phoneBook;

  // Add entries using the .emplace() function
  phoneBook.emplace("Lawton", 8675309);
  phoneBook.emplace("Jacqui", 2123487);
  phoneBook.emplace("Surya", 3097643);
  phoneBook.emplace("Victoria", 5397475);
  phoneBook.emplace("Antonio", 3473987);

  // Lookup the entry for "Jacqui" using the .at() function and print the result
  cout << phoneBook.at("Jacqui") << endl;

  // Lookup the entry for "Surya" using the .at() function and print the result
  cout << phoneBook.at("Surya") << endl;

  // Iterate through the map from beginning to end and print out each element's key and value
  for (const auto& entry : phoneBook) {
    cout << entry.first << ": " << entry.second << endl;
  }

  return 0;
}
