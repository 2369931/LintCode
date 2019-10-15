#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

long long StringToInt (string str) {
    stringstream s;
    s << str;
    long long result = 0;
    s >> result;
    s.clear();
    return result;
}

string IntToString (int a) {
    stringstream ss;
    ss << a;
    string result = "";
    ss >> result;
    ss.clear();
    return result;
}

int reverseInteger(int n) {
    int flag = 1;
    if (n < 0) {
        n *= -1;
        flag = -1;
    }
    string str = IntToString(n);
    int m = str.length();
    if (m == 0) {
        return 0;
    }
    else if (m == 1) {
        return n*flag;
    }
    string result = "";
    for (int i = m - 1;i >= 0;i--) {
        if (str[m] != '0') {
            result = result + str[i];
        }
    }
    long long temp = StringToInt(result);
    if (temp <= 2147483647)
        return (int)flag*temp;
    else
        return 0;
}

int main() {
    int test = 1534236469;
    cout << reverseInteger(test) << endl;
    return 0;
}


