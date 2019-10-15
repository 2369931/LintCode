#include <iostream>
#include <vector>
#include <map>

using namespace std;

int slidingWindowUniqueElementsSum(vector<int> &nums, int k) {
    int n = nums.size();
    int result = 0;
    if (n == 0 || k == 0) {
        return result;
    }
    map<int, int> dict;
    for (int i = 0;i < min(k,n);i++) {
        if (dict.find(nums[i]) == dict.end()) {
            dict[nums[i]] = 1;
        }
        else {
            dict[nums[i]] += 1;
        }
    }
    int temp = 0;
    for (map<int,int>::iterator it = dict.begin();it != dict.end();it ++) {
        if (it->second == 1) {
            temp ++;
        }
    }
    result += temp;
    if (n > k) {
        int out = 0;
        for (int i = k;i < n;i++) {
            dict[nums[out]] --;
            if (dict[nums[out]] == 0) {
                temp --;
            }
            else if (dict[nums[out]] == 1) {
                temp ++;
            }
            if (dict.find(nums[i]) == dict.end()) {
                dict[nums[i]] = 1;
            }
            else {
                if (dict[nums[i]] == 1) {
                    temp --;
                }
                dict[nums[i]] += 1;
            }
            if (dict[nums[i]] == 1) {
                temp ++;
            }
            result += temp;
            out ++;
        }
    }
    return result;
}

int main() {
    int a[7] = {47,13,40,40,48,45,40};
    vector<int> test(a, a+7);
    cout << slidingWindowUniqueElementsSum(test, 5) << endl;
    return 0;
}
