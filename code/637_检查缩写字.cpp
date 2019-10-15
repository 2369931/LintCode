#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int stringToint(string s) {
    stringstream ss;
    ss << s;
    int res = 0;
    ss >> res;
    return res;
}

bool validWordAbbreviation(string &word, string &abbr) {
    int n = word.length();
    int m = abbr.length();
    if (n == 0 && m == 0) {
        return true;
    }
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (word[i] == abbr[j]) {
            i ++;
            j ++;
        }
        else if (abbr[j] == '0') {
            i ++;
            j ++;
        }
        else if (abbr[j] > '0' && abbr[j] <= '9') {
            string s = "";
            s += abbr[j];
            int temp = j+1;
            j ++;
            while (temp < m && abbr[temp] >= '0' && abbr[temp] <= '9') {
                s += abbr[temp];
                temp ++;
                j ++;
            }
            int value = stringToint(s);
            i += value;
        }
        else {
            return false;
        }
    }
    if (i == n && j == m)
        return true;
    else
        return false;
}

int main() {
    string a = "internationalization";
    string b = "i12iz4n";
    cout << validWordAbbreviation(a,b) << endl;
    return 0;
}
