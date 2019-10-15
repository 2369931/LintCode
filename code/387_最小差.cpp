#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int smallestDifference(vector<int> &A, vector<int> &B) {
    vector<int> record;
    vector<int> C;
    int a = A.size();
    int b = B.size();
    if (a == 0 && b == 0) {
        return 0;
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int i = 0;
    int j = 0;
    while (i < a && j < b) {
        if (A[i] < B[j]) {
            C.push_back(A[i]);
            record.push_back(0);
            i ++;
        }
        else if (A[i] >= B[j]){
            C.push_back(B[j]);
            record.push_back(1);
            j ++;
        }
    }
    if (i == a && j < b) {
        for (;j < b;j ++) {
            C.push_back(B[j]);
            record.push_back(1);
        }
    }
    else if (i < a && j == b) {
        for (;i < a;i ++) {
            C.push_back(A[i]);
            record.push_back(0);
        }
    }
    /*for (int i = 0;i < C.size();i++) {
        cout << C[i] << " ";
    }
    cout << endl;
    for (int i = 0;i < C.size();i++) {
        cout << record[i] << " ";
    }
    cout << endl;*/
    int result = INT_MAX;
    for (int i = 0;i < C.size()-1;i++) {
        if (record[i] != record[i+1]) {
            result = min(result, abs(C[i+1] - C[i]));
        }
    }
    return result;
}

int main() {
    int a[4] = {1,1,1,1};
    int b[4] = {1,1,1,1};
    vector<int> t1(a, a+4);
    vector<int> t2(b, b+4);
    cout << smallestDifference(t1, t2) << endl;
    return 0;
}
