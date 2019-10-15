#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int partition(int num) {
    int count = 0;
    if (num == 1) {
        return 0;
    }
    while (num > 1) {
        for (int i = 2;i <= num;i++) {
            if (num%i == 0) {
                num /= i;
                count ++;
                break;
            }
        }
    }
    return count;
}

int calculate(int n) {
    if (n == 1) return 0;
    int total = 0;
    for (int i = 2;i <= n;i++) {
        total += partition(i);
    }
    return total;
}

int main() {
    int n = 100000;
    //partition(n);
    cout << calculate(n) << endl;
    return 0;
}


