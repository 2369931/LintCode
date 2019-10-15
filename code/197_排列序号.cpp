#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
//out of time limit
void nextpermutation(vector<int> &A) {
    int n = A.size();
    if (n == 0 || n == 1) return;
    for (int i = n-1;i >= 0;i--) {
        for (int j = n-1;j > i;j--) {
            if (A[i] < A[j]) {
                swap(A[i],A[j]);
                sort(A.begin()+i+1,A.end());
                return;
            }
        }
    }
    sort(A.begin(),A.end());
    return;
}

long long permutationIndex(vector<int> &A) {
    long long result = 1;
    vector<int> B;
    for (int i = 0;i < A.size();i++) {
        B.push_back(A[i]);
    }
    sort(B.begin(),B.end());
    while (B != A) {
        nextpermutation(B);
        result++;
    }
    return result;
}
*/

long long cal_fac(int n) {
    long long result = 1;
    while (n > 1) {
        result *= n;
        n --;
    }
    return result;
}

long long permutationIndex(vector<int> &A) {
    int n = A.size();
    if (n == 1) return 1;
    long long result = 1;
    for (int i = 0;i < n;i++) {
        int temp = 0;
        for (int j = i+1;j < n;j++) {
            if (A[j] < A[i]) temp++;
        }
        result += temp*cal_fac(n-i-1);
    }
    return result;
}

int main() {
    int a[15] = {22,7,15,10,11,12,14,8,9,1,2,3,6,5,4};
    vector<int> test(a,a+15);
    cout << permutationIndex(test) << endl;
    return 0;
}


