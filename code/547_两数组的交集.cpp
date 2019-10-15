#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

bool mid_find(vector<int> &nums, int target, int start, int end) {
    int mid = (start + end) / 2;
    if (nums[mid] == target) {
        return true;
    }
    if (start < end) {
        if (nums[mid] > target)
            return mid_find(nums,target,start,mid);
        else
            return mid_find(nums,target,mid+1,end);
    }
    else {
        return false;
    }
}

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    vector<int> result;
    set<int> record;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    int n = nums1.size();
    int m = nums2.size();
    if (n == 0 || m == 0) {
        return result;
    }
    for (int i = 0;i < n;i ++) {
        if (mid_find(nums2,nums1[i],0,m-1)) {
            record.insert(nums1[i]);
        }
    }
    for (set<int>::iterator it = record.begin();it != record.end();it++) {
        result.push_back(*it);
    }
    return result;
}

int main() {
    int a[4] = {1,2,2,1};
    int b[2] = {2,2};
    vector<int> test1(a,a+4);
    vector<int> test2(b,b+2);
    vector<int> result = intersection(test1,test2);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    return 0;
}
