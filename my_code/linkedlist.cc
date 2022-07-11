#include <iostream>
#include <string>

using namespace std;

struct node {
  int data;
  int key;
  struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void printList() {
  struct node *ptr = head;
  cout << "\n[";
  while (ptr != NULL) {
    cout << ptr->key << " " << ptr->data;
    ptr = ptr->next;
  }
  cout << " ]";
}

void insertFirst(int key, int data) {
  struct node *link = (struct node*)malloc(sizeof(struct node));
  link->key = key;
  link->data = data;
  link->next = head;
  head = link;
}

struct node *deleteFirst() {
  struct node *templink = head;
  head = head->next;
  return templink;
}

bool isEmpty() {
  return head == NULL;
}

int length() {
  int length = 0;
  struct node *current;
  for (current = head; current != NULL; current = current->next) {
    length++;
  }
  return length;
}

struct node *find(int key) {
  struct node *current = head;
  if (head == NULL) {
    return NULL;
  }
  while (current->key != key) {
    if (current->next == NULL) {
      return NULL;
    } else {
      current = current->next;
    }
  }
  return current;
}

struct node *Delete(int key) {
  struct node *current = head;
  struct node *previous = NULL;
  if (head == NULL) {
    return NULL;
  }
  while (current->key != key) {
    if (current->next == NULL) {
      return NULL;
    } else {
      previous = current;
      current = current->next;
    }
  }
  if (current == head) {
    head = head->next;
  } else {
    previous->next = current->next;
  }
  return current;
}

void sort() {
  int i, j, k, tempKey, tempData;
  struct node *current;
  struct node *next;
  int size = length();
  k = size;
  for (i = 0; i < size - 1; i++, k--) {
    current = head;
    next = head->next;
    for (j = 1; j < k; j++) {
      if (current->data > next->data) {
        tempData = current->data;
        current->data = next->data;
        next->data = tempData;
        tempKey = current->key;
        current->key = next->key;
        next->key = tempKey;
      }
      current = current->next;
      next = next->next;
    }
  }
}

void reverse(struct node **head_ref) {
  struct node *prev = NULL;
  struct node *current = *head_ref;
  struct node *next;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head_ref = prev;
}

int main() {
  insertFirst(1,10);
  insertFirst(2,20);
  insertFirst(3,30);
  insertFirst(4,1);
  insertFirst(5,40);
  insertFirst(6,56); 
  cout << "Original List : ";
  printList();
  while (!isEmpty()) {
    struct node *temp = deleteFirst();
    cout << "\nDeleted Value : ";
    cout << temp->key << " " << temp->data;
  }
  cout << "\nList after deleting all items : ";
  printList();
  insertFirst(1,10);
  insertFirst(2,20);
  insertFirst(3,30);
  insertFirst(4,1);
  insertFirst(5,40);
  insertFirst(6,56);
  cout << "\nRestored List : ";
  printList();
  cout << "\n";
  struct node *foundLink = find(4);
  if (foundLink != NULL) {
    cout << "Element found : ";
    cout << foundLink->key << " " << foundLink->data;
    cout << "\n";
  } else {
    cout << "Element not found\n";
  }
  cout << "\n";
  sort();
  cout << "List after sorting the data : \n";
  printList();
  reverse(&head);
  cout << "\nList after reversing the data : \n";
  printList();
  cout << "\n";
}

/*
  let 3 candidates be A, B, C
  A = 687905 votes
  B = 495086 votes
  C = 93756 votes 

  Total votes of 3 candidates in the election is = A + B + C
                                                 = 687905 + 495086 + 93756
                                                 = 1276747
  
  No. of invalid votes  = 13849
  No. of persons did not vote  = 25467

  Therefore total number of votes = 1276747 - 13849 - 25467
                                  = 1237431

  Total no of votes registered = 1237431
*/