#include <iostream>
#include <vector>

using namespace std;

void rerange(vector<int> &A) {
    int n = A.size();
    int a = 0;
    int b = 0;
    for (int i = 0;i < n;i++) {
        if (A[i] > 0) a++;
        else b ++;
    }
    if (a >= b) {
        if (A[0] < 0) {
            for (int i = 1;i < n;i++) {
                if (A[i] > 0) {
                    swap(A[0],A[i]);
                }
            }
        }
    }
    else {
        if (A[0] > 0) {
            for (int i = 1;i < n;i++) {
                if (A[i] < 0) {
                    swap(A[0],A[i]);
                }
            }
        }
    }
    for (int i = 1;i < n; i++) {
        if (A[i]*A[i-1] > 0) {
            for (int j = i+1;j < n;j++) {
                if (A[j]*A[i-1] < 0) {
                    swap(A[j],A[i]);
                    break;
                }
            }
        }
    }
}

int main() {
    int a[5] = {-3,2,-2,1,-4};
    vector<int> test(a,a+5);
    rerange(test);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << " ";
    }
    return 0;
}
