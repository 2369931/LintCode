#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*int triangleCount(vector<int> &S) {
    int result = 0;
    int n = S.size();
    if (n == 0) return result;
    for (int i = 0;i < n;i ++) {
        for (int j = i+1;j < n;j++) {
            for (int k = j+1;k < n;k++) {
                if (S[k] < (S[i] + S[j]) && S[k] > (abs(S[i] - S[j]))) {
                    //cout << S[i] << " " << S[j] << " " << S[k] << " " << endl;
                    result ++;
                }
            }
        }
    }
    return result;
}*/
int triangleCount(vector<int> &S) {
    int result = 0;
    int n = S.size();
    if (n == 0) return result;
    sort (S.begin(), S.end());
    for (int i = 0;i < n;i ++) {
        for (int j = i+1;j < n;j++) {
            int l = i + 1;
            int r = j;
            int target = S[j] - S[i];
            while (l < r) {
                int mid = (l + r)/2;
                if (target < S[mid]) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            result += (j - l);
        }
    }
    return result;
}

int main() {
    int a[4] = {3,4,6,7};
    vector<int> test(a,a+4);
    cout << triangleCount(test) << endl;
    return 0;
}
