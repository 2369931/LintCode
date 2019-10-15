#include <iostream>
#include <vector>

using namespace std;


void sum(vector<int> &A, int k, int target, vector<vector<int> > &result,vector<int> &temp, int i) {
    if (k == 0&&target == 0) {
        result.push_back(temp);
        return;
    }
    else if (i >= A.size() || target < 0) return;
    else {
        temp.push_back(A[i]);
        sum(A,k-1,target-A[i],result,temp,i+1);
        temp.pop_back();
        sum(A,k,target,result,temp,i+1);
    }
}

vector<vector<int> > kSumII(vector<int> &A, int k, int target) {
    vector<vector<int> > result;
    vector<int> temp;
    sum(A,k,target,result,temp,0);
    return result;
}

int main() {
    int a[5] = {1,2,3,4,7};
    vector<int> test(a,a+5);
    vector<vector<int> > result =  kSumII(test,2,5);
    for (int i = 0;i < result.size();i++) {
        cout << result[i][0] << " " << result[i][1] << endl;
    }
    return 0;
}

