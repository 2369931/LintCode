#include <iostream>

using namespace std;

void mergeSortedArray(int A[], int m, int B[], int n) {
    int C[m+n];
    int i = 0;
    int j = 0;
    int l = 0;
    while (i < m || j < n) {
        if (A[i] <= B[j] && i < m) {
            C[l] = A[i];
            l++;
            i++;
        }
        else if (A[i] <= B[j] && i >= m) {
            C[l] = B[j];
            l++;
            j++;
        }
        else if (A[i] >= B[j] && j < n){
            C[l] = B[j];
            l++;
            j++;
        }
        else if (A[i] >= B[j] && j >= n){
            C[l] = A[i];
            l++;
            i++;
        }
    }
    for (int k = 0;k < m+n;k++) {
        A[k] = C[k];
    }
}

int main() {
    return 0;
}
