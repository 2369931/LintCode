#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int> &height) {
    int n = height.size();
    if (n == 0) return 0;
    int result = INT_MIN;
    for (int i = 0;i < n;i++) {
        int width = 1;
        int h = height[i];
        for (int k = i-1;k >= 0;k--) {
            if (h <= height[k])
                width ++;
            else
                break;
        }
        for (int j = i+1;j < n;j++) {
            if (h <= height[j])
                width ++;
            else
                break;
        }
        if (result < width * h)
            result = width * h;
    }
    return result;
}

/*
int largestRectangleArea(vector<int> &height) {
    int res = 0;
    stack<int> s;
    height.push_back(0);
    for (int i = 0; i < height.size(); ++i) {
        if (s.empty() || height[s.top()] < height[i]) s.push(i);
        else {
            int cur = s.top();
            s.pop();
            res = max(res, height[cur] * (s.empty() ? i : (i - s.top() - 1)));
            --i;
        }
    }
    return res;
}
*/

int main() {
    int a[9] = {1,8,6,2,5,4,8,3,7};
    vector<int> test(a,a+9);
    cout << largestRectangleArea(test) << endl;
    return 0;
}
