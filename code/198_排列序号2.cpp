#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long cal_fac(int n) {
    if (n == 0) return 1;
    long long result = 1;
    while (n > 1) {
        result *= n;
        n --;
    }
    return result;
}

long long permutationIndexII(vector<int> &A) {
    int n = A.size();
    if (n == 1) return 1;
    long long result = 1;
    long long fac = 1;
    for (int i = 0;i < n;i++) {
        int temp = 0;
        long long dup = 1;
        map<int, int> record;
        record[A[i]] = 1;
        for (int j = i+1;j < n;j++) {
            if (A[j] < A[i]) temp++;
            record[A[j]]++;
            if (record[A[j]] > 1) dup *=  record[A[j]];
        }
        result += temp*cal_fac(n-i-1)/dup;
    }
    return result;
}

long long solve(vector<int>& A) {
    // Write your code here
    int size = A.size();
    if (size <= 0) {
        return 0;
    }

    long long result = 1, fac = 1, base = 1, dup = 1;
    map<int, int> hashRepeat;
    for (int i = size - 1; i >= 0; i--) {
        hashRepeat[A[i]]++;
        if (hashRepeat[A[i]] > 1) {
            dup *= hashRepeat[A[i]];
        }
        int count = 0;
        for (int j = i + 1; j < size; j++) {
            if (A[j] < A[i]) {
                count++;
            }
        }
        cout << i << " :: "  << count << " :: " << fac << " :: " << dup << endl;
        result += count * fac / dup;
        fac *= (size - i);
    }
    return result;
}

int main() {
    int a[5] = {3,2,2,1,1};
    vector<int> test(a,a+5);
    cout << permutationIndexII(test) << endl;
    aaa(test);
    return 0;
}



