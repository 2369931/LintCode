#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int longestPalindromeSubseq(string &s) {
    int n = s.length();
    if (n == 0) {
        return 0;
    }
    int record[n][n];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            record[i][j] = 0;
        }
    }
    for (int i = 0;i < n;i++) {
        record[i][i] = 1;
        for (int j = i-1;j >= 0;j--) {
            if (s[i] == s[j]) {
                record[j][i] = record[j+1][i-1] + 2;
            }
            else {
                record[j][i] = max(record[j][i-1],record[j+1][i]);
            }
        }
    }
    return record[0][n-1];
}

int main() {
    string s = "bbbab";
    cout << longestPalindromeSubseq(s) << endl;
    return 0;
}
