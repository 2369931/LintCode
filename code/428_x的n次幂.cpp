#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double myPow(double x, int n) {
    if (n == 0) {
        return 1;
    }
    if (abs(x-0) < 1e-6) {
        return 0;
    }
    if (n == INT_MIN) {
        return 0;
    }
    int record = 1;
    double result = x;
    while (record < abs(n)) {
        if (2*record <= abs(n)) {
            result = result*result;
            record *= 2;
        }
        else {
            result *= x;
            record += 1;
        }
    }
    if (n < 0) {
        result = 1/result;
    }
    return result;
}

int main() {
    cout << myPow(2,-2147483648) << endl;
    return 0;
}
