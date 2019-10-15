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

string one_multiply(string &num1, char num2) {
    string res = "";
    if (num1 == "0" || num2 == '0') {
        res = "0";
        return res;
    }
    int flag = 0;
    int i = num1.length() - 1;
    while (i >= 0) {
        int temp = (num1[i] - '0') * (num2 - '0') + flag;
        if (temp >= 10) {
            flag = temp/10;
            temp = temp%10;
        }
        else {
            flag = 0;
        }
        res = (char)(temp + '0') + res;
        i--;
    }
    if (flag != 0) {
        res = char(flag + '0') + res;
    }
    return res;
}

string multiply(string &num1, string &num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    int n = num1.length();
    int m = num2.length();
    if (n < m) {
        string temp = num1;
        num1 = num2;
        num2 = temp;
        int t = n;
        n = m;
        m = t;
    }
    string res = "0";
    for (int i = m-1;i >= 0;i --) {
        string temp = one_multiply(num1,num2[i]);
        int j = i;
        while (m > j+1) {
            temp = temp + "0";
            j ++;
        }
        //cout << temp << endl;
        res = addStrings(res,temp);
    }
    return res;
}

int main() {
    string a = "712871872812";
    string b = "32";
    char c = '3';
    //cout << one_multiply(a,c) << endl;
    cout << multiply(a,b) << endl;
    return 0;
}
