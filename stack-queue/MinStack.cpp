//https://leetcode.com/problems/min-stack/description/
#include <bits/stdc++.h>

using namespace std;

int getMin(stack<int> myStack) {
  if (myStack.empty()) {
    cout << "Stack is empty." << endl;
    return -1; // Or throw an exception
  }

  int minVal = myStack.top();
  while (!myStack.empty()) {
    minVal = min(minVal, myStack.top());
    myStack.pop();
  }
  return minVal;
}

int main() {
  stack<int> myStack;  // Create an empty stack of integers

  int choice, value;

  do {
    cout << "\nMenu:" << endl;
    cout << "1. Push element" << endl;
    cout << "2. Pop element" << endl;
    cout << "3. Top element (without popping)" << endl;
    cout << "4. Check if empty" << endl;
    cout << "5. Size of stack" << endl;
    cout << "6. Minimum value" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter value to push: ";
        cin >> value;
        myStack.push(value);
        cout << value << " pushed to stack." << endl;
        break;
      case 2:
        if (!myStack.empty()) {
          value = myStack.top();
          myStack.pop();
          cout << value << " popped from stack." << endl;
        } else {
          cout << "Stack is empty." << endl;
        }
        break;
      case 3:
        if (!myStack.empty()) {
          value = myStack.top();
          cout << "Top element: " << value << endl;
        } else {
          cout << "Stack is empty." << endl;
        }
        break;
      case 4:
        cout << (myStack.empty() ? "Stack is empty." : "Stack is not empty.") << endl;
        break;
      case 5:
        cout << "Size of stack: " << myStack.size() << endl;
        break;
      case 6: // Add a new case for getMin
        cout << "Minimum element: " << getMin(myStack) << endl;
        break;
      case 0:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice." << endl;
    }
  } while (choice != 0);

  return 0;
}
