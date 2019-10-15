#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int number = 0;

bool isHappy(int n) {
    if (n == 1) {
        return true;
    }
    else if (number > 100) {
        return false;
    }
    int next_n = 0;
    int record = n;
    while(n) {
        next_n += (n%10)*(n%10);
        n = n/10;
    }
    if (next_n == record) {
        return false;
    }
    number += 1;
    isHappy(next_n);
}

int main() {
    cout << isHappy(5) << endl;
    return 0;
}
