#include <iostream>
#include <vector>

using namespace std;

class ZigzagIterator2 {
public:
    vector<int> res;
    vector<int> record;
    ZigzagIterator2(vector<vector<int>>& vecs) {
        int n = vecs.size();
        int sum = 0;
        for (int i = 0; i < n;i++) {
            sum += vecs[i].size();
            record.push_back(vecs[i].size());
        }
        while (res.size() < sum) {
            for (int i = 0;i < n;i++) {
                if (record[i] != 0) {
                    int index = vecs[i].size() - record[i];
                    res.push_back(vecs[i][index]);
                    record[i] --;
                }
            }
        }
    }

    int next() {
        int temp = res.front();
        res.erase(res.begin());
        return temp;
    }

    bool hasNext() {
        if (res.size() > 0) {
            return true;
        }
        else {
            return false;
        }
    }
};
