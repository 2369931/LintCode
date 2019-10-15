#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string spilt(string &str, int s, int e) {
    string result = "";
    if (s >= e) return result;
    for (int i = s;i < e;i++) {
        result += str[i];
    }
    return result;
}

bool wordBreak(string &s, unordered_set<string> &dict) {
    if (s == "") return true;
    else if (dict.size() == 0) return false;
    bool dp[s.length()+1];
    for (int i = 0;i <= s.length();i++) {
        dp[i] = false;
    }
    int max_length = 0;
    unordered_set<string>::iterator it = dict.begin();
    while (it != dict.end()) {
        if (max_length  < (*it).length())
            max_length = (*it).length();
        it ++;
    }
    dp[0] = true;
    for (int i = 1;i <= s.length();i++) {
        int start = (i>max_length)?i-max_length:0;
        for (int j = start;j < i;j++) {
            string temp = spilt(s,j,i);
            auto it = dict.find(temp);
            if (dp[j] && it != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.length()];
}

int main () {
    return 0;
}
