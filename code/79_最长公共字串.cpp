#include <iostream>
#include <string>
#include <limits>

using namespace std;

int longestCommonSubstring(string &A, string &B) {
    int n = A.length();
    int m = B.length();
    if (n == 0 || m == 0) {
        return 0;
    }
    int result = INT_MIN;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            int length = 0;
            int index_a = i + 1;
            int index_b = 0;
            if (A[i] == B[j]) {
                index_b = j + 1;
                length++;
            }
            while (index_a < n && index_b < m) {
                if (A[index_a] == B[index_b]) {
                    index_a++;
                    index_b++;
                    length++;
                }
                else break;
            }
            if (length > result) result = length;
        }
    }
    return result;
}

int main() {
    string A = "www.lintcode.com code";
    string B = "www.ninechapter.com code";
    cout << longestCommonSubstring(A,B) << endl;
    return 0;
}
