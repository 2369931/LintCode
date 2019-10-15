#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> topk(vector<int> &nums, int k) {
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0;i < n;i++) {
        if (q.size() < k) {
            q.push(nums[i]);
        }
        else {
            int temp = q.top();
            if (temp < nums[i]) {
                q.pop();
                q.push(nums[i]);
            }
        }
    }
    vector<int> res;
    for (int i = 0;i < k;i ++) {
        res.insert(res.begin(),q.top());
        q.pop();
    }
    return res;
}

int main() {
    int a[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> test(a,a+8);
    vector<int> res = topk(test,5);
    for (int i = 0;i < res.size();i++) {
        cout << res[i] << " ";
    }
    return 0;
}
