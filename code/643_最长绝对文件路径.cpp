#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

bool find_point(string s) {
    for (int i = 0;i < s.length();i++) {
        if (s[i] == '.') {
            return true;
        }
    }
    return false;
}

int lengthLongestPath(string &input) {
    int res = 0;
    int level = 0;
    int n = input.length();
    map<int, int> record;
    record[0] = 0;
    for (int i = 0;i < n;i++) {
        int start = i;
        while (i < n && input[i] != '\n' && input[i] != '\t') {
            i ++;
        }
        if (i >= n || input[i] == '\n') {
            string s = input.substr(start,i - start);
            cout << s << endl;
            if (find_point(s)) {
                res = max(res,record[level] + (int)s.length());
            }
            else {
                level ++;
                record[level] = record[level-1] + (int)s.length() + 1;
            }
            level = 0;
        }
        else {
            level ++;
        }
    }
    return res;
}

int main() {
    string str = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    cout << lengthLongestPath(str) << endl;
    int a = 1;
    int b = 32;
    return 0;
}
