#include <iostream>
#include <queue>
using namespace std;

int main() {
  // Create a queue that holds doubles
  queue<double> myQueue;

  // Push 2.4 onto the queue
  myQueue.push(2.4);

  // Print the front of the queue
  cout << myQueue.front() << endl;

  // Push 7.5 onto the queue
  myQueue.push(7.5);

  // Print the front of the queue
  cout << myQueue.front() << endl;

  // Push 3.14 onto the queue
  myQueue.push(3.14);

  // Print the front of the queue
  cout << myQueue.front() << endl;

  // Print the size of the queue
  cout << myQueue.size() << endl;

  // Pop the queue
  myQueue.pop();

  // Print the front of the queue
  cout << myQueue.front() << endl;

  // Print the size of the queue
  cout << myQueue.size() << endl;

  // Pop the queue
  myQueue.pop();

  // Print the front of the queue
  cout << myQueue.front() << endl;

  // Pop the queue
  myQueue.pop();

  // Print the size of the queue
  cout << myQueue.size() << endl;

  return 0;
}
