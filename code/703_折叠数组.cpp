#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > fold(vector<vector<int> > temp, int key) {
    int n = temp.size();
    int m = temp[0].size();
    vector<vector<int> > res;
    if (key == 0) {
        for (int i = n - 1;i >= 0;i--) {
            vector<int> t;
            for (int j = m/2 - 1; j >= 0;j --) {
                t.push_back(temp[i][j]);
            }
            res.push_back(t);
        }
        for (int i = 0;i < n;i++) {
            vector<int> t;
            for (int j = m/2; j < m;j ++) {
                t.push_back(temp[i][j]);
            }
            res.push_back(t);
        }
    }
    else if (key == 1) {
        for (int i = n - 1;i >= 0;i--) {
            vector<int> t;
            for (int j = m - 1; j >= m/2;j --) {
                t.push_back(temp[i][j]);
            }
            res.push_back(t);
        }
        for (int i = 0;i < n;i++) {
            vector<int> t;
            for (int j = 0; j < m/2;j ++) {
                t.push_back(temp[i][j]);
            }
            res.push_back(t);
        }
    }
    return res;
}

vector<int> folding(vector<int> &nums, vector<int> &req) {
    int n = nums.size();
    int m = req.size();
    if (n == 0 || m == 0) {
        return nums;
    }
    vector<int> res;
    vector<vector<int> > temp;
    temp.push_back(nums);
    for (int i = 0; i < req.size();i++) {
        temp = fold(temp, req[i]);
    }
    for (int i = 0;i < temp.size();i++) {
        for (int j = 0;j < temp[i].size();j++) {
            res.push_back(temp[i][j]);
        }
    }
    return res;
}

int main() {
    int a[8] = {1,2,3,4,5,6,7,8};
    vector<int> test(a,a+8);
    int b[3] = {0,0,1};
    //int b[1] = {0};
    vector<int> req(b,b+3);
    vector<int> res = folding(test,req);
    for (int i = 0;i < res.size();i++) {
        cout << res[i] << " ";
    }
    return 0;
}

