#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int woodCut(vector<int> &L, int k) {
    long long sum = 0;
    long long max_length = INT_MIN;
    for (int i = 0;i < L.size();i++) {
        sum += L[i];
        if (L[i] > max_length) {
            max_length = L[i];
        }
    }
    if (sum < k) {
        return 0;
    }
    for (long long i = max_length;i >= 1;i--) {
        long long temp = 0;
        for (int j = 0;j < L.size();j++) {
            temp += L[j]/i;
        }
        if (temp >= k) {
            return i;
        }
    }
}

int main() {
    int a[3] = {232,124,456};
    vector<int> test(a,a+3);
    cout << woodCut(test,7) << endl;
    return 0;
}
