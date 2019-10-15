#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int longestIncreasingSubsequence(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    vector<int> record;
    int result = INT_MIN;
    for (int i = 0;i < nums.size();i++) {
        record.push_back(1);
    }
    for (int i = 0;i < nums.size();i++) {
        for (int j = 0;j < i;j++) {
            if (nums[i] > nums[j] && record[j] + 1 > record[i])
                record[i] = record[j] + 1;
        }
        if (record[i] > result) {
            result = record[i];
        }
    }
    return result;
}

int main() {
    int a[7] = {10,1,11,2,12,3,11};
    vector<int> test(a,a+7);
    cout << longestIncreasingSubsequence(test) << endl;
    return 0;
}
