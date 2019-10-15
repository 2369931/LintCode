#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2;i * i < num;i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool isSumOfKPrimes(int n, int k) {
    if (n < 2*k || k <= 0) {
        return false;
    }
    if (k == 1) {
        return isPrime(n);
    }
    if (n % 2 == 0) {
        if (k % 2 == 0) {
            return true;
        }
        else {
            return isSumOfKPrimes(n - 2, k - 1);
        }
    }
    else {
        if (k % 2 == 0) {
            return isSumOfKPrimes(n - 2, k - 1);
        }
        else {
            return isSumOfKPrimes(n - 3, k - 1);
        }
    }
}

int main() {
    cout << isSumOfKPrimes(10, 2) << endl;
    return 0;
}

