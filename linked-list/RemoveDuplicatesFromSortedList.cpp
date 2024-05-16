//https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
#include <bits/stdc++.h>

class ListNode {
public:
  int val;
  ListNode* next;

  ListNode(int value) {
    val = value;
    next = NULL;
  }
};

// Function to create a sample linked list
ListNode* createList(int arr[], int n) {
  ListNode* head = new ListNode(arr[0]);
  ListNode* current = head;
  for (int i = 1; i < n; i++) {
    current->next = new ListNode(arr[i]);
    current = current->next;
  }
  return head;
}

ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL or head->next==NULL)return head;
    ListNode* p=head;
    while(p!=NULL and p->next!=NULL){
        if(p->val==p->next->val){
            p->next=p->next->next;
        }
        else{
            p=p->next;
        }
    }
    return head;
  }

int main() {
  int arr[] = {1, 2, 2, 3, 4, 4, 5, 5, 5, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Create linked list from the array
  ListNode* head = createList(arr, n);

  ListNode* newHead = deleteDuplicates(head);

  // Print the modified list (optional)
  while (newHead) {
    std::cout << newHead->val << " -> ";
    newHead = newHead->next;
  }
  std::cout << "NULL" << std::endl;

  return 0;
}
