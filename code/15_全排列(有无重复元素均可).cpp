#include <iostream>
#include <vector>

using namespace std;

bool isSwap(vector<int> &nums,int i,int j) {
    for (int k = j;k < i;k++) {
        if (nums[k] == nums[i]) {
            return false;
        }
    }
    return true;
}

void swap(vector<int> &nums,int i,int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void calculate(vector<vector<int> > &result,vector<int> &nums,int n) {
    if (n == nums.size()) {
        result.push_back(nums);
    }
    else {
        for (int i = n;i < nums.size();i++) {
            if (isSwap(nums,i,n)) {
                swap(nums,i,n);
                calculate(result,nums,n+1);
                swap(nums,i,n);
            }
        }
    }
}
vector<vector<int> > permute(vector<int> &nums) {
    vector<vector<int> > result;
    if (nums.size() == 0) {
        vector<int> nothing;
        result.push_back(nothing);
        return result;
    }
    else {
        calculate(result,nums,0);
        return result;
    }
}

int main() {
    int a[4] = {1,2,2,4};
    vector<int> temp(a,a+4);
    vector<vector<int> > result = permute(temp);
    for (int i = 0;i < result.size();i++) {
        for (int j = 0;j < result[i].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

