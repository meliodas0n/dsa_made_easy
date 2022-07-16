#include <iostream>

using namespace std;

struct ListNode {
  int data;
  struct ListNode *next;
};

int ListLength(struct ListNode *head) {
  struct ListNode *current = head;
  int count = 0;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

void insertInLinkedList(struct ListNode **head, int data, int position) {
  int k = 1;
  struct ListNode *p, *q, *newNode;
  newNode = (ListNode *)malloc(sizeof(struct ListNode));
  if (!newNode) {
    cout << "Memory Error";
    return;
  }
  newNode->data = data;
  p = *head;
  if (position == 1) {
    newNode->next = p;
    *head = newNode;
  } else {
    while ((p != NULL) and (k < position)) {
      k++;
      q = p;
      p = p->next;
    }
    q->next = newNode;
    newNode->next = p;
  }
}

void DeleteNodeFromLinkedList(struct ListNode **head, int position) {
  int k = 1;
  struct ListNode *p, *q;
  if (*head == NULL) {
    cout << "List Empty!";
    return;
  }
  p = *head;
  if (position == 1) {
    *head = (*head)->next;
    free(p);
    return;
  } else {
    while ((p != NULL) and (k < position)) {
      k++;
      q = p;
      p = p->next;
    }
    if (p == NULL) {
      cout << "Position does not exist";
    } else {
      q->next = p->next;
      free(p);
    }
  }
}

void deleteLinkedList(struct ListNode **head) {
  struct ListNode *auxilaryNode, *iterator;
  iterator = *head;
  while (iterator) {
    auxilaryNode = iterator->next;
    free(iterator);
    iterator = auxilaryNode;
  }
  *head = NULL;
}

int main() {

}