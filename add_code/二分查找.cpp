#include <iostream>
#include <vector>

using namespace std;

int binary_find(vector<int> &nums, int start, int end, int target) {
    if (start > end) return -1;
    int mid = (start + end)/2;
    if (nums[mid] == target) {
        return mid;
    }
    else if (nums[mid] < target) {
        binary_find(nums,mid+1,end,target);
    }
    else if (nums[mid] > target){
        binary_find(nums,start,mid-1,target);
    }
}

int main() {
    int a[5] = {1,2,3,4,6};
    vector<int> test(a,a+5);
    cout << binary_find(test,0,test.size()-1,6) << endl;
    return 0;
}
