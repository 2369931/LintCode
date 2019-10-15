#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &A, int target) {
    if (A.size() == 0) {
        return -1;
    }
    int start = 0;
    int end = A.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (A[mid] == target) {
            return mid;
        }
        else if (A[mid] >= A[start]) {
            if (A[mid] > target && A[start] <= target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        else {
            if (A[mid] < target && A[end] >= target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

    }
    return -1;
}

int main() {
    int a[5] = {4,5,1,2,3};
    vector<int> test(a,a+5);
    int result = search(test,5);
    cout << result << endl;
    return 0;
}
