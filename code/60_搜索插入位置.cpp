#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &A, int target) {
    int index = 0;
    int n = A.size();
    if (n == 0) return 0;
    if (target > A[n-1]) return n;
    if (target < A[0]) return 0;
    for (int i = 0;i < n;i++) {
        if (target == A[i]) return i;
        else if (i < n - 1 && target > A[i] && target < A[i+1])
            return i + 1;
    }
}

int main() {
    int a[4] = {1,3,5,6};
    vector<int> test(a,a+4);
    int result = searchInsert(test,0);
    cout << result << endl;
    return 0;
}
