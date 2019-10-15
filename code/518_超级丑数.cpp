#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int nthSuperUglyNumber(int n, vector<int> &primes) {
    int m = primes.size();
    if (m == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    vector<long long> record;
    record.push_back(1);
    sort(primes.begin(),primes.end());
    while (record.size() < n) {
        long long max_value = record[record.size()-1];
        long long value = INT_MAX;
        for (int i = 0;i < primes.size();i++) {
            for (int j = 0;j < record.size();j++) {
                long long temp = primes[i]*record[j];
                if (temp > max_value) {
                    value = min(temp,value);
                }
            }
        }
        record.push_back(value);
    }
    return (int)record[n-1];
}

int main() {
    int a[4] = {2,7,13,19};
    vector<int> test(a,a+4);
    cout << nthSuperUglyNumber(12,test) << endl;
    return 0;
}
