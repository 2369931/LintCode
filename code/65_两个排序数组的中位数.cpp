#include <iostream>
#include <vector>
#include <limits>

using namespace std;

double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    if (n < m) return findMedianSortedArrays(B,A);
    int L1,L2,R1,R2,C1,C2;
    int start = 0;
    int end = 2*m;
    while (start <= end) {
        C1 = (start + end) / 2;
        C2 = m + n - C1;
        if (C1 == 0) L1 = INT_MIN;
        else L1 = B[(C1-1)/2];
        if (C1 == 2*m) R1 = INT_MAX;
        else R1 = B[C1/2];
        if (C2 == 0) L2 = INT_MIN;
        else L2 = A[(C2-1)/2];
        if (C2 == 2*n) R2 = INT_MAX;
        else R2 = A[C2/2];

        if (L1 > R2)
            end = C1 - 1;
        else if (L2 > R1)
            start = C1 + 1;
        else
            break;
    }
    return (max(L1,L2) + min(R1,R2))/2.0;
}

int main() {
    int a[6] = {1,2,3,4,5,6};
    vector<int> A(a,a+6);
    int b[4] = {2,3,4,5};
    vector<int> B(b,b+4);
    cout << findMedianSortedArrays(A,B) << endl;
    return 0;
}
