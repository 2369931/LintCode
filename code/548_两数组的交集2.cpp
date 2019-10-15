#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    vector<int> result;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int n = nums1.size();
    int m = nums2.size();
    if (n == 0 || m == 0) {
        return result;
    }
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (nums1[i] == nums2[j]) {
            result.push_back(nums1[i]);
            i ++;
            j ++;
        }
        else if (nums1[i] > nums2[j]) {
            j ++;
        }
        else {
            i ++;
        }
    }
    return result;
}

int main() {
    int a[3] = {1,1,2};
    int b[1] = {1};
    vector<int> test1(a,a+3);
    vector<int> test2(b,b+1);
    vector<int> result = intersection(test1,test2);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    return 0;
}
