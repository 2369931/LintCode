#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isUgly(int num) {
    if (num == 0) {
        return false;
    }
    if (num < 0) {
        return false;
    }
    int flag = 0;
    while (num) {
        if (num%2 == 0) {
            flag = 1;
            num = num/2;
        }
        if (num%3 == 0) {
            flag = 1;
            num = num/3;
        }
        if (num%5 == 0) {
             flag = 1;
            num = num/5;
        }
        if (num == 1) {
            return true;
        }
        else if (flag == 1){
            flag = 0;
            continue;
        }
        else {
            return false;
        }
    }
}

int main() {
    cout << isUgly(8) << endl;
    return 0;
}
