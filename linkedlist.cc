#include <iostream>

using namespace std;

struct ListNode {
  int data;
  struct ListNode *next;
};

void print(struct ListNode *head) {
  struct ListNode *curr = head;
  for (curr = head; curr != NULL; curr = curr->next) {
    cout << curr->data << " ";
  }
  cout << "\n";
}

int length(struct ListNode *head) {
  int count = 0;
  struct ListNode *curr = head;
  for (curr = head; curr != NULL; curr = curr->next) {
    count++;
    curr = curr->next;
  }
  return count;
}

struct ListNode *insertAtBeginning(struct ListNode *head, int data) {
  struct ListNode *temp;
  temp = (struct ListNode *)malloc(sizeof(struct ListNode));
  temp->data = data;
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
    head->next = NULL;
  } else {
    temp->next = head;
    head = temp;
  }
  return head;
}

int main() {

  return 0;
}