#include <iostream>
#include <cmath>

using namespace std;

int sqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }
    double result = 1;
    double pre_result = 0;
    while (abs(result - pre_result) > 1e-6) {
        pre_result = result;
        result = (pre_result + x/pre_result)/2;
    }
    return (int)result;
}

int main() {
    cout << sqrt(3) << endl;
    cout << sqrt(4) << endl;
    cout << sqrt(5) << endl;
    cout << sqrt(10) << endl;
    return 0;
}
