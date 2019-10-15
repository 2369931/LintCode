#include <iostream>
#include <vector>
#include <map>

using namespace std;
//两个数抵消
int majorityNumber(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    map<int,int> record;
    for (int i = 0;i < n;i++) {
        record[nums[i]] ++;
        if (record[nums[i]] > n/3) {
            return nums[i];
        }
    }
}

int main() {
    int a[7] = {99,2,99,2,99,3,3};
    //int a[8] = {2,-1,3,-4,5,-8,6,-7};
    //int a[6] = {1,-1,2,1,3,1};
    vector<int> test(a,a+7);
    int result = majorityNumber(test);
    cout << result << endl;
    return 0;
}
