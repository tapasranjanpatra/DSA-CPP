#include <iostream>
#include <queue>

using namespace std;

int main() {
  priority_queue<int> pq; // Create a priority queue to store integers

  int num;
  cout << "Enter some integers (enter -1 to stop):\n";
  while (true) {
    cin >> num;
    if (num == -1) break; // Stop taking input when -1 is entered
    pq.push(num); // Push the input number into the priority queue
  }

  // Print the elements in the priority queue
  cout << "Elements in the priority queue: ";
  while (!pq.empty()) {
    cout << pq.top() << " "; // Print the top element in the queue
    pq.pop(); // Remove the top element from the queue
  }

  return 0;
}
