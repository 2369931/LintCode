#include <iostream>
#include <cmath>

using namespace std;

int countOnes(int num) {
    int result = 0;
    while (num) {
        num = num & (num - 1);
        result ++;
    }
    return result;
}

int main() {
    cout << countOnes(5) << endl;
    return 0;
}
