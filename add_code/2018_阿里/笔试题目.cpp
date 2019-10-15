#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxArea(vector<int> &height) {
    int n = height.size();
    if (n < 2) {
        return 0;
    }
    int start = 0;
    int end = height.size()- 1;
    int maxV = INT_MIN;
    while(start < end) {
        int contain = min(height[end], height[start]) * (end - start);
        maxV = max(maxV, contain);
        if(height[start] <= height[end]) {
            start++;
        }
        else {
            end--;
        }
    }
    return maxV;
}

int main() {
    int a[9] = {1,8,6,2,5,4,8,3,7};
    vector<int> test(a,a+9);
    cout << maxArea(test) << endl;
    return 0;
}
