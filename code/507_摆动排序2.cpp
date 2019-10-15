#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void wiggleSort(vector<int>& nums) {
    int size = nums.size();
    if (size <= 0) {
        return;
    }
    vector<int> temp = nums;
    int k = (size + 1) / 2, j = size;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < size; ++i) {
        nums[i] = i & 1 ? temp[--j] : temp[--k];
    }
}
