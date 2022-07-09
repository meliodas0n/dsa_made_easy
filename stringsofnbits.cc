// Generate all the strings of n bits. Assume A[0,,,n-1] is an array of size n.

/* #include <stdio.h>

void solution(char record[], int start, int last) {
    if (start == last) {
        printf(" %s \n", record);
        return;
    }
    record[start] = '0';
    solution(record, start + 1, last);
    record[start] = '1';
    solution(record, start + 1, last);
}

void binaryString(int n) {
    if (n <= 0) {
        return;
    }
    char record[n];
    printf("Digit : %d\n", n);
    solution(record, 0, n);
}

int main(int argc, char const * argv[]) {
    int n;
    scanf("%d", &n);
    binaryString(n);
    return 0;
}
 */

#include <iostream>
#include <climits>

using namespace std;

void printTheArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void generateAllBinaryStrings(int n, int arr[], int i) {
    if (i == n) {
        printTheArray(arr, n);
        return;
    }
    arr[i] = 0;
    generateAllBinaryStrings(n, arr, i + 1);
    arr[i] = 1;
    generateAllBinaryStrings(n, arr, i + 1);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    generateAllBinaryStrings(n, arr, 0);
    return 0;
} 


// THIS CODE IS A JOKE
// int A[100];

/* void binary(int N) {
    if (N == 1) {
        printf("%d", *A);
    } else {
        A[N - 1] = 0;
        binary(N - 1);
        A[N - 1] = 1;
        binary(N - 1);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    binary(N);
    return 0;
} */