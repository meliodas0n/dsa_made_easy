#include <iostream>
#include <climits>

using namespace std;

#define size 4

int top = -1;
int a[size];

void push() {
  int x;
  if (top == size - 1) {
    cout << "Overflow" << "\n";
  } else {
    cout << "Enter the element needed to pushed : ";
    cin >> x;
    top += 1;
    a[top] = x;
  }
}

void pop() {
  if (top == -1) {
    cout << "Underflow" << "\n";
  } else {
    cout << "Poppped Element : " << a[top] << "\n";
    top -= 1;
  }
}

void show() {
  if (top == -1) {
    cout << "\nUnderflow" << "\n";
  } else {
    cout << "\nElements present in the stack : \n";
    for (int i = top; i >= 0; i--) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
}

int main() {
  int choice;
  while (1) {
    cout << "Operations performed by Stack" << "\n";
    cout << "1. Push\n2. Pop\n3. Show\n4. End\n";
    cout << "Enter you choice : ";
    cin >> choice;
    switch (choice) {
    case 1: push();
            break;
    case 2: pop();
            break;
    case 3: show();
            break;
    case 4: 
            exit(0);
    default: cout << "\nInvalid Choice\n";
    }
  }
  return 0;
}