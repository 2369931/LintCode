#include <iostream>
#include <vector>

using namespace std;

int longestIncreasingContinuousSubsequence(vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return 0;
    }
    int temp = 1;
    int max_up = 1;
    int max_down = 1;
    for (int i = 1;i < n;i++) {
        if (A[i] > A[i-1]) {
            temp ++;
            max_up = max (max_up,temp);
        }
        else {
            temp = 1;
        }
    }
    temp = 1;
    for (int i = 1;i < n;i++) {
        if (A[i] < A[i-1]) {
            temp ++;
            max_down = max (max_down,temp);
        }
        else {
            temp = 1;
        }
    }
    return max (max_down, max_up);
}
