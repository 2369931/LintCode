#include <iostream>
#include <string>

using namespace std;

string addStrings(string &num1, string &num2) {
    string res = "";
    int n = num1.length();
    int m = num2.length();
    int i = n - 1;
    int j = m - 1;
    int flag = 0;
    while (i >= 0 && j >= 0) {
        int a = num1[i] - '0';
        int b = num2[j] - '0';
        int temp = a + b + flag;
        if (temp >= 10) {
            temp = temp%10;
            flag = 1;
        }
        else {
            flag = 0;
        }
        res = (char)(temp + '0') + res;
        i --;
        j --;
    }
    while (i >= 0) {
        int temp = num1[i] - '0' + flag;
        if (temp >= 10) {
            temp = temp%10;
            flag = 1;
        }
        else {
            flag = 0;
        }
        res = (char)(temp + '0') + res;
        i --;
    }
    while (j >= 0) {
        int temp = num2[j] - '0' + flag;
        if (temp >= 10) {
            temp = temp%10;
            flag = 1;
        }
        else {
            flag = 0;
        }
        res = (char)(temp + '0') + res;
        j --;
    }
    if (flag == 1) {
        res = '1' + res;
    }
    return res;
}

int main() {
    string a = "99";
    string b = "1";
    cout << addStrings(a,b) << endl;
    return 0;
}
