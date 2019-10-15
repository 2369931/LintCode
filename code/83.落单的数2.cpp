#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string.h>

using namespace std;

int singleNumberII(vector<int> &A) {
    map<int,int> record;
    for (int i = 0;i < A.size();i++) {
        record[A[i]] += 1;
    }
    int result = 0;
    for (auto &p : record) {
        if (p.second == 1) {
            result = p.first;
            break;
        }
    }
    return result;
}

int singleNumberII(vector<int> &A) {
    int result[35];
    memset(result, 0, sizeof(result));
    for (int i = 0;i < A.size();i++) {
        for (int j = 0;j < 32;j++) {
            result[j] = (result[j] + ((A[i] >> j)&1))%3;
        }
    }
    int ans = 0;
    int base = 1;
    for (int i = 0;i < 32;i++) {
        ans += result[i]*base;
        base *= 2;
    }
    return ans;
}

int main() {
    int a[16] = {6,1,1,1,2,2,2,4,5,6,4,5,0,4,5,6};
    vector<int> test(a,a+16);
    cout << singleNumberII(test) << endl;
    return 0;
}
