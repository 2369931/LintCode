#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <stdio.h>

using namespace std;

int divide(int dividend, int divisor) {
    if (divisor == 0) {
        return INT_MAX;
    }
    int flag = 1;
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        flag = -1;
    }
    long long d1 = abs((long)dividend);
    long long d2 = abs((long)divisor);
    long long result = 0;
    while (d1 >= d2) {
        long long temp = d2;
        long long cnt = 1;
        while (d1 >= temp) {
            d1 -= temp;
            result += cnt;
            cnt = cnt << 1;
            temp = temp << 1;
        }
    }
    result *= flag;
    if (result > INT_MAX || result < INT_MIN) {
        return 2147483647 ;
    }
    return result;
}

int main() {
    cout << divide(-2147483648,1) << endl;
    int u=010, v= 0x10, w=10;
    printf("%d,%d,%d/n",u,v,w);
    printf("\bre\¡¯hi\¡¯y\\\bou\n");
    return 0;
}

