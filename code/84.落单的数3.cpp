#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string.h>

using namespace std;

vector<int> singleNumberIII(vector<int> &A) {
    map<int,int> record;
    for (int i = 0;i < A.size();i++) {
        record[A[i]] += 1;
    }
    vector<int> result;
    for (auto &p : record) {
        if (result.size() == 2) {
            break;
        }
        if (p.second == 1) {
            result.push_back(p.first);
        }
    }
    return result;
}


int main() {
    int a[8] = {1,2,2,3,4,4,5,3};
    vector<int> test(a,a+8);
    //cout << singleNumberII(test) << endl;
    return 0;
}
