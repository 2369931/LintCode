#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> change(int num,int n) {
    vector<int> result;
    while(num > 0) {
        result.insert(result.begin(),num%2);
        num = num/2;
    }
    while (result.size() != n) {
        result.insert(result.begin(),0);
    }
    return result;
}

vector<vector<int> > subsets(vector<int> &nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int> > result;
    int n = pow(2,nums.size());
    for (int i = 0;i < n;i++) {
        vector<int> temp;
        vector<int> flag = change(i,nums.size());
        for (int j = 0;j < flag.size();j++) {
            if (flag[j] == 1) {
                temp.push_back(nums[j]);
            }
        }
        result.push_back(temp);
    }
    return result;
}

int main() {
    int a[3] = {1,0,4};
    vector<int> temp(a,a+3);
    vector<vector<int> > result = subsets(temp);
    for (int i = 0;i < result.size();i++) {
        for (int j = 0;j < result[i].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

