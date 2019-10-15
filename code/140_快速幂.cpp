#include <iostream>
#include <limits>

using namespace std;

int fastPower(int a, int b, int n) {
    if (n == 1) {
        return a%b;
    }
    else if (n == 0) {
        return 1%b;
    }
    long temp = fastPower(a,b,n/2);
    temp = (temp * temp)%b;
    if (n%2 == 1)
        temp = (temp * (a%b))%b;
    return (int)temp;
}

int main() {
    return 0;
}
