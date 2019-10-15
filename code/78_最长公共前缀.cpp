#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    int length = INT_MAX;
    string result = "";
    if (strs.size() == 0) {
        return "";
    }
    if (strs.size() == 1) {
        return strs[0];
    }
    for (int i = 0;i < strs.size();i++) {
        if (length > strs[i].length()) {
            length = strs[i].length();
        }
    }
    for (int i = 0;i < length;i++) {
        char temp = strs[0][i];
        int flag = 0;
        for (int j = 1;j < strs.size();j ++) {
            if (strs[j][i] != temp) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) result += temp;
    }
    return result;
}

int main() {
    string A = "abcd";
    string B = "abca";
    vector<string> test;
    test.push_back(A);
    test.push_back(B);
    cout << longestCommonPrefix(test) << endl;
    return 0;
}

