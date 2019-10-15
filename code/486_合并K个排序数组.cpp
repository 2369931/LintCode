#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
    vector<int> result;
    int n = arrays.size();
    if (n == 0) {
         return result;
    }
    for (int i = 0;i < arrays.size();i++) {
        for (int j = 0;j < arrays[i].size();j++) {
            result.push_back(arrays[i][j]);
        }
    }
    sort(result.begin(),result.end());
    return result;
}

//可以使用堆排序
