#include <iostream>
#include <string>

using namespace std;

string spilt(string &s, int i, int j) {
    string result = "";
    for (int k = i;k <= j;k++) {
        result += s[k];
    }
    return result;
}

string reverseWords(string &s) {
    if (s == "") return s;
    string result = "";
    int i = 0;
    int end = 0;
    int flag = 0;
    while (i < s.length()) {
        flag = 0;
        if (s[i] == ' ') {
            i++;
            continue;
        }
        for (int j = i;j < s.length();j++) {
            if (s[j] == ' ') {
                end = j-1;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            end = s.length() - 1;
        }
        result = spilt(s,i,end) + " " + result;
        i = end+1;
    }
    return result;
}

int main() {
    string test = " 123  456";
    cout << reverseWords(test) << endl;
    return 0;
}
