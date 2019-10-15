#include <iostream>
#include <vector>
#include <map>

using namespace std;

int majorityNumber(vector<int> &nums,int k) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    map<int,int> record;
    for (int i = 0;i < n;i++) {
        record[nums[i]] ++;
        if (record[nums[i]] > n/k) {
            return nums[i];
        }
    }
}

int main() {
    int a[10] = {3,1,2,3,2,3,3,4,4,4};
    //int a[8] = {2,-1,3,-4,5,-8,6,-7};
    //int a[6] = {1,-1,2,1,3,1};
    vector<int> test(a,a+10);
    int result = majorityNumber(test,3);
    cout << result << endl;
    return 0;
}
