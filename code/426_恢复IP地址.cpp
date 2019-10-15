#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <map>

using namespace std;

bool judge(string s) {
    int temp = atoi(s.c_str());
    if (temp > 255 || temp < 0) {
        return false;
    }
    else if (s.length() > 1 && s[0] == '0') {
        return false;
    }
    else {
        return true;
    }
}

string spilt(string s, int start, int end) {
    string str = "";
    for (int i = start;i <= end;i++) {
        str += s[i];
    }
    return str;
}

vector<string> restoreIpAddresses(string &s) {
    int n = s.length();
    vector<string> result;
    if (n < 4 || n > 12) {
        return result;
    }
    string str1 = "";
    string str2 = "";
    string str3 = "";
    string str4 = "";
    for (int i = 0;i < 3;i++) {
        str1 = spilt(s,0,i);
        if (judge(str1) && (n - str1.length() <= 9)) {
            for (int j = i+1;j < i+4;j++) {
                str2 = spilt(s,i+1,j);
                if (judge(str2) && (n - str1.length() - str2.length() <= 6)) {
                    for (int k = j+1;k < j+4;k++) {
                        str3 = spilt(s,j+1,k);
                        if (judge(str3) && (n - str1.length() - str2.length() - str3.length() <= 3)) {
                            for (int q = k+1;q < k+4;q++) {
                                str4 = spilt(s,k+1,q);
                                if (judge(str4) && n == str1.length() + str2.length() + str3.length() + str4.length()) {
                                    result.push_back(str1 + "." + str2 + "." + str3 + "." + str4);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    string test = "00000";
    vector<string> result = restoreIpAddresses(test);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << endl;
    }
    return 0;
}
