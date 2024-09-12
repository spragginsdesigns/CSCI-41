#include <iostream>
#include <stack>
using namespace std;

int main() {
  // Create a stack that holds ints
  stack<int> myStack;

  // Push 5 onto the stack
  myStack.push(5);

  // Print the top of the stack
  cout << myStack.top() << endl;

  // Push 7 onto the stack
  myStack.push(7);

  // Print the top of the stack
  cout << myStack.top() << endl;

  // Push 3 onto the stack
  myStack.push(3);

  // Print the top of the stack
  cout << myStack.top() << endl;

  // Print the size of the stack
  cout << myStack.size() << endl;

  // Pop the stack
  myStack.pop();

  // Print the top of the stack
  cout << myStack.top() << endl;

  // Print the size of the stack
  cout << myStack.size() << endl;

  // Pop the stack
  myStack.pop();

  // Print the top of the stack
  cout << myStack.top() << endl;

  // Pop the stack
  myStack.pop();

  // Print the size of the stack
  cout << myStack.size() << endl;

  return 0;
}
