#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool judge (string str) {
    int i = 0;
    int j = str.length()-1;
    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
        i ++;
        j --;
    }
    return true;
}

void dfs(vector<vector<string>> &result, vector<string> &temp, string &str, int index) {
    if (index == str.length()) {
        result.push_back(temp);
    }
    for (int i = index;i < str.length();i++) {
       string s = str.substr(index, i - index + 1);
       if (judge(s)) {
            temp.push_back(s);
            dfs(result,temp,str,i+1);
            temp.pop_back();
       }
    }
}

vector<vector<string>> partition(string &s) {
    vector<vector<string> > result;
    if (s.length() == 0) return result;
    vector<string> temp;
    dfs(result,temp,s,0);
    return result;
}

int main() {
}
