#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> &A, int target) {
    if (A.size() == 0) {
        return false;
    }
    int start = 0;
    int end = A.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (A[mid] == target) {
            return true;
        }
        else if (A[mid] > A[start]) {
            if (A[mid] > target && A[start] <= target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        else if (A[mid] == A[start]) {
            start ++;
        }
        else if (A[mid] < A[end]){
            if (A[mid] < target && A[end] >= target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        else if (A[mid] == A[end]) {
            end --;
        }
    }
    return false;
}

int main() {
    int a[8] = {3,4,4,5,7,0,1,2};
    vector<int> test(a,a+8);
    bool result = search(test,7);
    cout << result << endl;
    return 0;
}
