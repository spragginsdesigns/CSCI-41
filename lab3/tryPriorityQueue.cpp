#include <iostream>
#include <queue>
using namespace std;

int main() {
  // Create a priority queue that holds ints
  priority_queue<int> pq;

  // Push {1, -2, 3, -4, ..., 49, -50} onto the priority queue, in that order
  for (int i = 1; i <= 50; ++i) {
    if (i % 2 == 0) {
      pq.push(-i);
    } else {
      pq.push(i);
    }
  }

  // In a loop, do the following while the priority queue isn't empty:
  // 1. Print the top of the priority queue
  // 2. Pop the priority queue
  while (!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
  }

  return 0;
}
