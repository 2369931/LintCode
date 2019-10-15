#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*int maxArea(vector<int> &heights) {
    int n = heights.size();
    int max_value = 0;
    if (n == 0) return max_value;
    for (int i = 0;i < n;i++) {
        for (int j = i+1;j < n;j++) {
            int temp = min(heights[i], heights[j]) * (j - i);
            if (max_value < temp) {
                max_value = temp;
            }
        }
    }
    return max_value;
}*/

int maxArea(vector<int> &heights) {
    int n = heights.size();
    int max_value = 0;
    if (n == 0) return max_value;
    int l = 0;
    int r = n - 1;
    while (l < r) {
        max_value = max(max_value, min(heights[l], heights[r]) * (r - l));
        if (heights[l] < heights[r]) {
            l ++;
        }
        else {
            r --;
        }
    }
    return max_value;
}

int main() {
    int a[3] = {1,3,2};
    vector<int> test(a,a+3);
    cout << maxArea(test) << endl;
    return 0;
}
