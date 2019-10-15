#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string &s) {
    if (s == "") return 0;
    int max_length = 0;
    map<char, int> record;
    int length = 0;
    for (int i = 0;i < s.length();i++) {
        map<char, int>::iterator it = record.find(s[i]);
        if (it == record.end()) {
            record[s[i]] = i;
            length ++;
        }
        else {
            if (record[s[i]] + length < i) {
                length ++;
            }
            else {
                max_length = max(max_length, length);
                length = i - record[s[i]];
            }
            record[s[i]] = i;
        }
    }
    max_length = max(max_length, length);
    return max_length;
}

int main() {
    string test = "abcabcbb";
    cout << lengthOfLongestSubstring(test) << endl;
    return 0;
}
