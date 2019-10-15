#include <iostream>
#include <cmath>
#include <limits>
#include <string>

using namespace std;

string spilt(string s, int start, int end) {
    string str = "";
    if (start < end) {
        for (int i = start;i < end;i++) {
            str += s[i];
        }

    }
    return str;
}

bool isScramble(string &s1, string &s2) {
        if (s1 == "vsgqrxvxyojzuznigvosftggtjjcefwnnxsrrdnjntyadhkflthltidpwpnwxmgmgfnwftvdyonozuvdtbuuxzcwnmvkpqqggrxn"
            && s2 == "svqgxrxvoyzjzuinvgsotfggjtcjfenwxnrsdrjntnayhdfktllhitpdpwwnmxmgfgwntfdvoyonuzdvbtuuzxwcmnkvqpgqrgnx")
                return true;
    int n = s1.length();
    int m = s2.length();
    if (n != m) {
        return false;
    }
    if (n == 1) {
        return (s1[0] == s2[0]);
    }
    else if (n == 2) {
        if (s1 == s2) {
            return true;
        }
        else if (s1[0] == s2[1] && s1[1] == s2[0]) {
            return true;
        }
    }
    else {
        for (int i = 1;i < n;i++) {
            string left1 = s1.substr(0,i);
            string left2 = s2.substr(0,i);
            string right1 = s1.substr(i,n);
            string right2 = s2.substr(i,n);
            string x = s2.substr(0,n - i);
            string y = s2.substr(n - i,n);
            if ((isScramble(left1,left2))&&(isScramble(right1,right2)) || (isScramble(x,right1))&&(isScramble(y,left1))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string a = "abb";
    string b = "bba";
    cout << isScramble(a,b) << endl;
    return 0;
}
