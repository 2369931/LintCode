#include <iostream>
#include <vector>
#include <string>

using namespace std;

string addBinary(string &a, string &b) {
    string result = "";
    int n = a.length();
    int m = b.length();
    if (n < m) {
        string str = a;
        a = b;
        b = str;
        n = a.length();
        m = b.length();
    }
    if (n == 0 && m == 0) {
        return result;
    }
    if (n == 0 && m != 0) {
        return a;
    }
    if (n != 0 && m == 0) {
        return b;
    }
    int i = n - 1;
    int j = m - 1;
    int flag = 0;
    char temp = '0';
    while (i >= 0 && j >= 0) {
        if (a[i] == '0' && b[j] == '0') {
            if (flag == 0) {
                temp = '0';
            }
            else {
                temp = '1';
                flag = 0;
            }
        }
        else if (a[i] == '1' && b[j] == '0') {
            if (flag == 0) {
                temp = '1';
            }
            else {
                temp = '0';
                flag = 1;
            }
        }
        else if (a[i] == '0' && b[j] == '1') {
            if (flag == 0) {
                temp = '1';
            }
            else {
                temp = '0';
                flag = 1;
            }
        }
        else if (a[i] == '1' && b[j] == '1') {
            if (flag == 0) {
                temp = '0';
                flag = 1;
            }
            else {
                temp = '1';
                flag = 1;
            }
        }
        i --;
        j --;
        result = temp + result;
    }
    if (i != -1) {
        if (flag == 0) {
            for (int p = i;p >= 0; p--) {
                result = a[p] + result;
            }
        }
        else {
            for (int p = i;p >= 0; p--) {
                char str_temp = a[p];
                if (a[p] == '1' && flag == 1) {
                    str_temp = '0';
                    flag = 1;
                }
                else if (a[p] == '0' && flag == 1) {
                    str_temp = '1';
                    flag = 0;
                }
                else if (a[p] == '1' && flag == 0) {
                    str_temp = '1';
                    flag = 0;
                }
                else if (a[p] == '0' && flag == 0) {
                    str_temp = '0';
                    flag = 0;
                }
                result = str_temp + result;
            }
        }
    }
    if (flag == 1){
        result = "1" + result;
    }
    return result;
}

int main() {
    string a = "101";
    string b = "111";
    cout << addBinary(a,b) << endl;
    return 0;
}
