
#include <iostream>
#include <cmath>

using namespace std;

int nthUglyNumber(int n) {
    int result[n];
    result[0] = 1;
    int a = 0;
    int b = 0;
    int c = 0;
    int j = 1;
    while (j < n) {
        int next = min(result[a]*2,min(result[b]*3,result[c]*5));
        if (next == result[a]*2) {
            a ++;
        }
        else if (next == result[b]*3) {
            b ++;
        }
        else {
            c ++;
        }
        if (next == result[j-1]) {
            continue;
        }
        result[j] = next;
        cout << result[j] << endl;
        j ++;
    }
    return result[n-1];
}

int main() {
    int n;
    cin >> n;
    cout << nthUglyNumber(n) << endl;
    return 0;
}
