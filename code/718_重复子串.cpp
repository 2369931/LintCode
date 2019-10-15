#include <iostream>
#include <string>

using namespace std;

bool judge(string a, string b) {
    int n = a.length();
    int m = b.length();
    if (n == m) {
        return a == b;
    }
    else {
        if (n < m) {
            string temp = a;
            a = b;
            b = temp;
            int t = n;
            n = m;
            m = t;
        }
        for (int i = 0;i < m;i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
}
int repeatedString(string &A, string &B) {
    int n = A.length();
    int m = B.length();
    if (n == 0 && m != 0) {
        return -1;
    }
    if (m == 0) {
        return 1;
    }
    if (n > m) {
        for (int i = 0;i <= n - m;i ++) {
            if (A[i] == B[0]) {
                if (A.substr(i,n) == B) {
                    return 1;
                }
            }
        }
        return -1;
    }
    int index = 0;
    bool flag = false;
    int res = 0;
    for (int i = 0;i <= m - n;i ++) {
        if (B[i] == A[0]) {
            if (B.substr(i,n) == A) {
                index = i;
                flag = true;
                break;
            }
        }
    }
    if (!flag) {
        return -1;
    }
    if (index != 0) {
        string begin_str = B.substr(0, index);
        if (begin_str == A.substr(A.length() - index, index) ) {
            res ++;
        }
        else {
            return -1;
        }
    }
    int j = index;
    while(j < m) {
        if (B[j] == A[0]) {
            if (judge(B.substr(j,n),A)) {
                res ++;
                j += n;
            }
            else {
                return -1;
            }
        }
    }
    return res;
}

int main() {
    string A = "abcd";
    string B = "cdabcdab";
    cout << repeatedString(A,B) << endl;
    return 0;
}
