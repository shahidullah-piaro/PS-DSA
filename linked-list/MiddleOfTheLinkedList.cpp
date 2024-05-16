//https://leetcode.com/problems/middle-of-the-linked-list/description/
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to create a new ListNode
ListNode* newNode(int data) {
    return new ListNode(data);
}

// Function to insert a node at the beginning of the linked list
void push(ListNode** head_ref, int new_data) {
    ListNode* new_node = new ListNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the contents of a linked list
void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to find the middle node of a linked list (optimized for single pass)
ListNode* middleNode(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head; // Handle empty or single-node lists
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Traverse the linked list using two pointers
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // If there are even nodes, slow points to the second middle node
    // (return either slow or slow->next depending on your preference)
    return slow;
}

int main() {
    ListNode* head = NULL;

    // Get linked list input from the user
    int numNodes, data;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> numNodes;

    cout << "Enter the data for each node (separated by spaces): ";
    for (int i = 0; i < numNodes; i++) {
        cin >> data;
        push(&head, data); // Insert at the beginning for efficiency
    }

    cout << "The original linked list: ";
    printList(head);

    // Find the middle node
    ListNode* middle = middleNode(head);

    if (middle != NULL) {
        cout << "The middle node of the linked list: " << middle->val << endl;
    } else {
        cout << "The linked list is empty." << endl;
    }

    return 0;
}

