#include <iostream>
#include <cmath>
using namespace std;
// count the number of 5
long long trailingZeros(long long n) {
    long long result = 0;
    int i = 1;
    while (pow(5,i) <= n) {
        result += n/(long)pow(5,i);
        i ++;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << trailingZeros(n) << endl;
    return 0;
}
