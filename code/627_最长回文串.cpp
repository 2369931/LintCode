#include <iostream>
#include <string>
#include <map>

using namespace std;

int longestPalindrome(string &s) {
    map<char,int> record;
    int res = 0;
    for (int i = 0;i < s.length();i++) {
        map<char,int>::iterator it = record.find(s[i]);
        if (it == record.end()) {
            record[s[i]] = 1;
        }
        else {
            record[s[i]] += 1;
        }
    }
    int single_length = 0;
    for (map<char,int>::iterator it = record.begin();it != record.end();it++) {
        if (it->second % 2 == 1) {
            if (it->second > single_length) {
                res += max(0,single_length - 1);
                single_length = it->second;
            }
            else {
                res += it->second - 1;
            }
        }
        else if (it->second % 2 == 0) {
            res += it->second;
        }
    }
    return res+single_length;
}

int main() {
    string s = "NTrQdQGgwtxqRTSBOitAXUkwGLgUHtQOmYMwZlUxqZysKpZxRoehgirdMUgy";
    cout << longestPalindrome(s) << endl;
    return 0;
}
