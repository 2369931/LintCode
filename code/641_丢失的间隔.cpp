#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

string intTostring(int a) {
    stringstream ss;
    ss << a;
    string temp = "";
    ss >> temp;
    return temp;
}

string change(int a, int b) {
    if (b == a) {
        return intTostring(a);
    }
    else {
        return intTostring(a) + "->" + intTostring(b);
    }
}

vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
    int n = nums.size();
    vector<string> res;
    if (n == 0) {
        res.push_back(change(lower,upper));
        return res;
    }
    if (lower < nums[0]) {
        res.push_back(change(lower,nums[0]-1));
    }
    for (int i = 0;i < n-1;i++) {
        if (nums[i+1] == nums[i]) {
            continue;
        }
        if (nums[i+1] != nums[i]+1 && nums[i+1] <= upper) {
            res.push_back(change(nums[i]+1,nums[i+1]-1));
        }
    }
    if (upper > nums[n-1]) {
        res.push_back(change(nums[n-1]+1,upper));
    }
    return res;
}

int main() {
    int a[5] = {-2147483648,-2147483648,0,2147483647,2147483647};
    vector<int> test(a,a+5);
    vector<string> res = findMissingRanges(test,-2147483648,2147483647);
    for (int i = 0;i < res.size();i++) {
        cout << res[i] << " ";
    }
    return 0;
}
