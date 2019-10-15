#include <iostream>
#include <vector>

using namespace std;

int trapRainWater(vector<int> &heights) {
    int n = heights.size();
    if (n == 0) return 0;
    int max_value = 0;
    int max_index = 0;
    for (int i = 0;i < n;i++) {
        if (heights[i] > max_value) {
            max_value = heights[i];
            max_index = i;
        }
    }
    int temp = heights[0];
    int result = 0;
    for (int i = 0;i < max_index;i++) {
        if (temp < heights[i]) temp = heights[i];
        else result += temp - heights[i];
    }
    temp = heights[n-1];
    for (int i = n-1;i > max_index;i--) {
        if (temp < heights[i]) temp = heights[i];
        else result += temp - heights[i];
    }
    return result;
}

int main() {
    int a[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> test(a,a+12);
    cout << trapRainWater(test) << endl;
    return 0;
}
