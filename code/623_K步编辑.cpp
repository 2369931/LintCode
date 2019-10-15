#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int min_distance(string &word1, string &word2) {
    int n = word1.length();
    int m = word2.length();
    int dp[n+1][m+1];
    for (int i = 0;i <= n;i++) {
        dp[i][0] = i;
    }
    for (int j = 0;j <= m;j++) {
        dp[0][j] = j;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1], dp[i-1][j])) + 1;
            }
        }
    }
    return dp[n][m];
}

vector<string> kDistance(vector<string> &words, string &target, int k) {
    vector<string> res;
    int n = words.size();
    if (n == 0) {
        return res;
    }
    for (int i = 0;i < n;i++) {
        int temp = words[i].length() - target.length();
        if (abs(temp) <= k) {
            if (min_distance(words[i],target) <= k) {
                res.push_back(words[i]);
            }
        }
    }
    return res;
}

int main() {
    string a[8] = {"as","ab","cf","da","ee","e","adee","eeda"};
    vector<string> test(a,a+8);
    string target = "eefab";
    vector<string> res = kDistance(test,target,3);
    for (int i = 0;i < res.size();i++) {
        cout << res[i] << endl;
    }
    return 0;
}
