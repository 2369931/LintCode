#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Vector2D {
public:
    vector<int> result;
    int index;

    Vector2D(vector<vector<int>>& vec2d) {
        index = 0;
        for (int i = 0;i < vec2d.size();i++) {
            for (int j = 0;j < vec2d[i].size();j++) {
                result.push_back(vec2d[i][j]);
            }
        }
    }

    int next() {
        int temp = result[index];
        index ++;
        return temp;
    }

    bool hasNext() {
        if (index < result.size()) {
            return true;
        }
        else {
            return false;
        }
    }
};
