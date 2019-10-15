#include <iostream>
#include <vector>
#include <map>

using namespace std;

int singleNumber(vector<int> &A) {
    if (A.size() == 0) return 0;
    int result = A[0];
    for (int i = 1;i < A.size();i++) {
        result ^= A[i];
    }
    return result;
}

int main() {
    int a[7] = {1,2,2,1,3,4,3};
    vector<int> test(a,a+7);
    cout << singleNumber(test) << endl;
    return 0;
}
