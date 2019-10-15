#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int sum (vector<int> &temp) {
    int result = 0;
    int n = temp.size();
    for (int i = 0;i < n;i++) {
        result += temp[i];
    }
    return result;
}

void create(vector<vector<int> > &result, vector<int> &num, vector<int> &temp, int cur, int n ,int target) {
    int sum_temp = sum(temp);
    if (sum_temp == target) {
        result.push_back(temp);
        return;
    }
    else if (sum_temp > target) {
        return;
    }
    for (int i = cur;i < n;i++) {
        temp.push_back(num[i]);
        create(result,num,temp,i+1,n,target);
        temp.pop_back();
    }
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    vector<vector<int> > result;
    int n = num.size();
    if (n == 0) return result;
    sort(num.begin(),num.end());
    vector<int> temp;
    create(result,num,temp,0,n,target);
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}

int main() {
    int a[7] = {10,1,6,7,2,1,5};
    vector<int> test(a,a+7);
    vector<vector<int> > result = combinationSum2(test,8);
    for (int i = 0;i < result.size();i++) {
        for (int j = 0;j < result[i].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

