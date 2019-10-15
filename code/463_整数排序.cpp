#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

void sortIntegers(vector<int> &A) {
    int n = A.size();
    if (n == 0 || n == 1) {
        return;
    }
    for (int i = 0;i < n;i++) {
        for (int j = i;j < n;j++) {
            if (A[i] > A[j]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

int main() {
    int a[4] = {4,1,16,8};
    vector<int> test(a,a+4);
    sortIntegers(test);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << " ";
    }
    return 0;
}
