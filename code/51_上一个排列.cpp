#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

bool check(vector<int> &nums, int i, int j) {
    bool result = true;
    if (j > i) {
        for (int k = i;k < j;k ++) {
            if (nums[k] == nums[j])
                return false;
        }
    }
    return result;
}

void calculate(vector<vector<int> > &result, vector<int> &nums, int n) {
    if (n == nums.size()) {
        result.push_back(nums);
    }
    else {
        for (int i = n;i < nums.size();i++) {
            if (check(nums,n,i)) {
                swap(nums,i,n);
                calculate(result,nums,n+1);
                swap(nums,i,n);
            }
        }
    }
}

vector<int> previousPermuation(vector<int> &nums) {
    /*vector<vector<int> > result;
    calculate(result,nums,0);
    for (int i = 0;i < result.size();i++) {
        for (int j = 0;j < result[i].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }*/

    if (nums.size() == 1) {
        return nums;
    }
    else if (prev_permutation(nums.begin(),nums.end())) {
        return nums;
    }
    else {
        vector<int> result = nums;
        //next_permutation(nums.begin(),nums.end());
        while (next_permutation(nums.begin(),nums.end())) {
            result = nums;
        }
        return result;
    }
}

int main() {
    int a[] = {1,2,3,4};
    vector<int> test(a,a+4);
    vector<int> result = previousPermuation(test);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
