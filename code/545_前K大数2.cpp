#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    priority_queue<int, vector<int>, less<int> > q;
    int length;
    int number;
    Solution(int k) {
        length = k;
        number = 0;
    }

    void add(int num) {
        q.push(num);
        number ++;
    }

    vector<int> topk() {
        vector<int> res;
        for (int i = 0;i < min(number,length);i++) {
            res.push_back(q.top());
            q.pop();
        }
        for (int i = 0;i < min(number,length);i++) {
            q.push(res[i]);
        }
        return res;
    }
};
