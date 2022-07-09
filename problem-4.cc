// Generate all strings of length n drawn from 0--k-1

#include <iostream>
#include <string>

using namespace std;

string A[100];

void k_string(int n, int k) {
    if (n < 1) {
        cout << A;
    } else {
        for (int j = 0; j < k; j++) {
            A[n - 1] = j;
            k_string(n - 1, k);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int k;
    cin >> k;
    k_string(n, k);
}