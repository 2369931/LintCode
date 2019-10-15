#include <iostream>
#include <vector>

using namespace std;

int findPeak(vector<int> &A) {
    int n = A.size();
    if (A[1] > A[2]) return 1;
    if (A[n-2] > A[n-3]) return n-2;
    int start = 1;
    int end = n-2;
    for (int i = start + 1;i < end;i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1])
            return i;
    }

}

int main() {
    int a[8] = {1, 2, 1, 3, 4, 5, 7, 6};
    vector<int> test(a,a+8);
    cout << findPeak(test) << endl;
    return 0;
}
