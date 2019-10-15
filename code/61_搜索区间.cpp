#include <iostream>
#include <vector>

using namespace std;

int find_right(vector<int> &A, int target) {
    int n = A.size();
    if (n == 0 || A[n-1] < target) return -1;
    if (A[n-1] == target) return A.size()-1;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right)/2;
        if (A[mid] < target) {
            left = mid + 1;
        }
        else if (A[mid] > target) {
            right = mid - 1;
        }
        else {
            if (A[mid+1] == target) {
                right ++;
            }
            else {
                return mid;
            }
        }
    }
    return -1;
}

int find_left(vector<int> &A, int target) {
    int n = A.size();
    if (n == 0 || A[0] > target) return -1;
    if (A[0] == target) return 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right)/2;
        if (A[mid] < target) {
            left = mid + 1;
        }
        else if (A[mid] > target) {
            right = mid - 1;
        }
        else {
            if (A[mid-1] == target) {
                left --;
            }
            else {
                return mid;
            }
        }
    }
    return -1;
}

vector<int> searchRange(vector<int> &A, int target) {
    vector<int> result;
    int left = find_left(A, target);
    int right = find_right(A, target);
    result.push_back(left);
    result.push_back(right);
    return result;
}

int main() {
    int a[6] = {5, 7, 7, 8, 8, 10};
    vector<int> test(a,a+6);
    vector<int> result = searchRange(test,5);
    for (int i = 0;i < result.size();i ++) {
        cout << result[i] << " ";
    }
    return 0;
}
