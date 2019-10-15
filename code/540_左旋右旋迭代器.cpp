#include <iostream>
#include <vector>

using namespace std;

class ZigzagIterator {
public:
    vector<int> result;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int i = 0;
        int j = 0;
        int n = v1.size();
        int m = v2.size();
        int flag = 1;
        while (i < n && j < m) {
            if (flag % 2 == 1) {
                result.push_back(v1[i]);
                i++;
            }
            else {
                result.push_back(v2[j]);
                j++;
            }
            flag ++;
        }
        while (i < n) {
            result.push_back(v1[i]);
            i++;
        }
        while (j < m) {
            result.push_back(v2[j]);
            j++;
        }
    }

    int next() {
        int temp = result.front();
        result.erase(result.begin());
        return temp;
    }

    bool hasNext() {
        if (result.size() > 0) {
            return true;
        }
        else {
            return false;
        }
    }
};
