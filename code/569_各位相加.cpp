#include <iostream>
#include <vector>

using namespace std;

int addDigits(int num) {
    if (num < 10) {
        return num;
    }
    else {
        int temp = 0;
        while(num) {
            temp += num%10;
            num /= 10;
        }
        addDigits(temp);
    }
}

int main() {
    cout << addDigits(38) << endl;
    return 0;
}
