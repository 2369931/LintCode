#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int reverseInteger(int number) {
    string num = "";
    stringstream stream;
    stream << number;
    stream >> num;
    int flag = 0;
    string result = "";
    for (int i = num.length()-1;i >= 0;i --) {
        if (flag == 0&&num[i] == '0') {
            continue;
        }
        else {
            result += num[i];
            flag = 1;
        }
    }
    return atoi(result.c_str());
}

int main() {
    reverseInteger(900);
    reverseInteger(105);
}
