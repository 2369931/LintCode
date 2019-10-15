#include <iostream>
#include <vector>

using namespace std;

int maxArray(vector<vector<int> > &record,vector<int> &nums,int i,int j) {
    if (record[i][j] != -999999) {
        return record[i][j];
    }
    int sum = nums[i];
    int result = nums[i];
    for (int k = i+1;k <= j;k++) {
        if (sum < 0) {
            sum = 0;
        }
        sum += nums[k];
        if (sum > result) {
            result = sum;
        }
    }
    record[i][j] = result;
    return result;
}

int value = 0;

void dp(vector<vector<int> > &record,vector<int> &nums,vector<int> &result,int i,int j,int k) {
    if (i > j || j-i+1 < k) {
        value = 0;
        return;
    }
    if (k == 1) {
        value += maxArray(record,nums,i,j);
        result.push_back(value);
        value = 0;
        return;
    }
    else {
        for (int l = i;l < j;l++) {
            //cout << maxArray(record,nums,i,l) << endl;
            value += maxArray(record,nums,i,l);
            dp(record,nums,result,l+1,j,k-1);
            //value = 0;
        }
    }
}

int maxSubArray(vector<int> &nums, int k) {
    vector<vector<int> > record;
    int n = nums.size();
    for (int i = 0;i < n;i++) {
        vector<int> temp;
        for (int j = 0;j < n;j++) {
            temp.push_back(-999999);
        }
        record.push_back(temp);
    }
    //cout << maxArray(record,nums,0,5) << endl;
    vector<int> result;
    dp(record,nums,result,0,n-1,k);
    int maxValue = -999999;
    for (int i = 0;i < result.size();i++) {
        //cout << result[i]-1215 << endl;
        if (result[i] > maxValue) {
            maxValue = result[i];
        }
    }
    return maxValue;
}

int main () {
    int a[9] = {2,-1,3,-4,5,-8,6,-7};
    //int a[8] = {2,-1,3,-4,5,-8,6,-7};
    //int a[6] = {1,-1,2,1,3,1};
    vector<int> test(a,a+9);
    int result = maxSubArray(test,4);
    cout << result << endl;
    //cout << result << endl;
    return 0;
}
