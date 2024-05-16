//https://leetcode.com/problems/reverse-linked-list/description/
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Function to create a new node
ListNode* newNode(int data) {
    return new ListNode(data);
}

// Function to insert a node at the beginning of the linked list
void push(ListNode** head_ref, int new_data) {
    ListNode* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the contents of the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to reverse the linked list (provided)
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

int main() {
    ListNode* head = NULL;

    // Get linked list input from the user
    cout << "Enter elements for the linked list (enter -1 to terminate):" << endl;
    int data;
    while (cin >> data && data != -1) {
        push(&head, data);
    }

    cout << "Original linked list: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    cout << "Reversed linked list: ";
    printList(head);

    return 0;
}

