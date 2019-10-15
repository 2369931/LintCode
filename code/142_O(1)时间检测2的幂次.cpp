#include <iostream>

using namespace std;

bool checkPowerOf2(int n) {
    if (n <= 0) return false;
    else if ((n & (n-1)) == 0) return true;
    else return false;
}

int main() {
}
