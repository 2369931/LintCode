#include <iostream>
#include <vector>

using namespace std;

int find_next(vector<int> &stones, int cur, int step) {
    for (int i = cur + 1;i < stones.size();i++) {
        if (stones[cur] + step == stones[i]) {
            return i;
        }
        if (stones[cur] + step < stones[i]) {
            return -1;
        }
    }
    return -1;
}

bool CanCross(vector<int> &stones, int cur, int lastStep) {
    if (cur == stones.size() - 1) {
        return true;
    }
    int next = 0;
    if ((next = find_next(stones, cur, lastStep + 1)) != -1
				&& CanCross(stones, next, lastStep + 1)) {
        return true;
    }
    if ((next = find_next(stones, cur, lastStep)) != -1
				&& CanCross(stones, next, lastStep)) {
        return true;
    }
    if ((next = find_next(stones, cur, lastStep - 1)) != -1
				&& CanCross(stones, next, lastStep - 1)) {
        return true;
    }
    return false;
}

bool canCross(vector<int> &stones) {
    for (int i = stones.size() - 1; i > 2; i --) {
        if (stones[i] > 2 * stones[i - 1])
            return false;
    }
    return CanCross(stones,0,1);
}

int main() {
    int a[8] = {0,1,3,5,6,8,12,17};
    vector<int> test(a,a+8);
    cout << canCross(test) << endl;
    return 0;
}
