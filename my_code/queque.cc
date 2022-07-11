#include <iostream>

using namespace std;

#define size 100 

int a[size];
int rear = -1;
int front = -1;

void enqeueu() {
  int insert_item;
  if (rear == size - 1) {
    cout << "Overflow\n";
  } else {
    if (front == -1) {
      front = 0;
      cout << "Element to be inserted in the queue\n";
      cin >> insert_item;
      rear = rear + 1;
      a[rear] = insert_item;
    }
  }
}

void dequeue() {
  if (front == -1 || front > rear) {
    cout << "Underflow\n";
    return;
  } else {
    cout << "Element deleted from the queue\n" << a[front];
    front = front + 1;
  }
}

void display() {
  if (front == -1) {
    cout << "Empty Queue\n";
  } else {
    cout << "Queue : \n";
    for (int i = front; i <= rear; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
}

int main() {
  int ch;
  while (1) {
    cout << "1. Enqeueu\n2. Deqeueue\n3. Display\n4. Exit\n";
    cout << "Enter your choice of operations : \n";
    cin >> ch;
    switch (ch) {
      case 1: enqeueu();
      break;
      case 2: dequeue();
      break;
      case 3: display();
      break;
      case 4: exit(0);
      default: cout << "Incorrect Data" << "\n";
    }
  }
  return 0;
}