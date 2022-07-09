#include <iostream>

using namespace std;

int isArrayInSortedOrder(int A[], int n) {
    if (n == 1) {
        return 1;
    }
    return (A[n - 1] < A[n - 2]) ? 0 : isArrayInSortedOrder(A, n - 1);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    isArrayInSortedOrder(arr, n);
    return 0;
}