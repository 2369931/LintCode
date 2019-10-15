#include <iostream>
#include <cmath>
#include <map>

using namespace std;
//±©Á¦ËÑË÷
bool checkSumOfSquareNumbers_1(int num) {
    if (num < 0) {
        return false;
    }
    if (num == 1) {
        return true;
    }
    for (int i = 0;i <= num/2;i ++) {
        for (int j = 0;j <= num/2;j ++) {
            if (i*i + j*j == num) {
                return true;
            }
        }
    }
    return false;
}

bool checkSumOfSquareNumbers(int num) {
    if (num < 0) {
        return false;
    }
    int tmp = sqrt(num);
    if (tmp * tmp == num) {
        return true;
    }
    map<int, int> dict;
    for (int i = 0;i <= tmp;i++) {
        dict[i*i] = i*i;
    }
    for (int i = tmp; i >= tmp/2; i--) {
        if(dict.find(i*i) != dict.end()) {
            if (dict.find(num - i*i) != dict.end()) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cout << checkSumOfSquareNumbers(5) << endl;
    return 0;
}
