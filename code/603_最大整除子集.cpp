#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums) {
    int res = 0;
    vector<int> result;
    vector<int> temp;
    map<int, vector<int> > record;
    int n = nums.size();
    if (n == 0) {
        return temp;
    }
    sort(nums.begin(),nums.end());
    for (int i = 0;i < n;i++) {
        temp.clear();
        for (int j = i-1;j >= 0;j--) {
            if (nums[i]%nums[j] == 0 && record[nums[j]].size() > temp.size()) {
                temp = record[nums[j]];
            }
        }
        temp.push_back(nums[i]);
        record[nums[i]] = temp;
    }
    for (map<int,vector<int> >::iterator c = record.begin();c != record.end();c++) {
        if (c->second.size() > result.size()) {
            result = c->second;
        }
    }
    return result;
}

int main() {
    int a[4] = {1,2,3};
    vector<int> test(a,a+3);
    vector<int> res = largestDivisibleSubset(test);
    for (int i = 0;i < res.size();i++) {
        cout << res[i] << " ";
    }
    return 0;
}
