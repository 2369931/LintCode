#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

bool judge(string s) {
    int n = s.length();
    if (n == 0 || n == 1) return true;
    int i = 0;
    int j = n - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string longestPalindrome(string &s) {
    int n = s.length();
    string result = "";
    int m_l = 0;
    for (int i = 0;i < n;i++) {
        for (int j = i;j < n;j++) {
            string temp1 = s.substr(i,j-i+1);
            if (j-i+1 > m_l && s[j] == s[i]) {
                string temp = s.substr(i,j-i+1);
                if (judge(temp)) {
                    result = temp;
                    m_l = j-i+1;
                }
            }
        }
    }
    return result;
}

int main() {
    string s = "iptmykvjanwiihepqhzupneckpzomgvzmyoybzfynybpfybngttozprjbupciuinpzryritfmyxyppxigitnemanreexcpwscvcwddnfjswgprabdggbgcillisyoskdodzlpbltefiz";
    cout << longestPalindrome(s) << endl;
    return 0;
}
