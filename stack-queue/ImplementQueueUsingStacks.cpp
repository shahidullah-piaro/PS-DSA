//https://leetcode.com/problems/implement-queue-using-stacks/description/
#include <bits/stdc++.h>

using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2; // Two stacks to simulate the queue

public:
    void enqueue(int x) {
        // Push all elements from s1 to s2 to maintain FIFO order
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new element to s1
        s1.push(x);

        // Move elements back from s2 to s1 to preserve the queue structure
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Or throw an exception for empty queue
        }

        int front = s1.top();
        s1.pop();
        return front;
    }

    bool isEmpty() {
        return s1.empty();
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        // Reversing elements temporarily for printing in FIFO order
        stack<int> temp = s1;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueUsingStacks q;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue();
                if (value != -1) {
                    cout << "Dequeued element: " << value << endl;
                }
                break;
            case 3:
                cout << "Queue elements: ";
                q.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}

