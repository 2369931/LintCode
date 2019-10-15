#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool compareStrings(string &A, string &B) {
    if (B == "") return true;
    vector<int> record;
    int num = 0;
    for (int i = 0;i < A.length();i++) {
        record.push_back(0);
    }
    for (int i = 0;i < B.length();i++) {
        for (int j = 0;j < A.length();j++) {
            if (B[i] == A[j] && record[j] == 0) {
                record[j] = 1;
                num ++;
                break;
            }
        }
    }
    if (num == B.length()) return true;
    else return false;
}

int main() {
    string a = "ABSDFABAB";
    string b = "ADB";
    cout << compareStrings(a,b) << endl;
    return 0;
}

