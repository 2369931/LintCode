#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

long long str_to_int(string str) {
    long long result = 0;
    stringstream ss;
    ss << str;
    ss >> result;
    ss.clear();
    return result;
}

string int_to_str(long long temp) {
    string result = "";
    stringstream ss;
    ss << temp;
    ss >> result;
    ss.clear();
    return result;
}

bool compare(string A,string B) {
    int n = A.length();
    int m = B.length();
    if (n > m) return true;
    else if (n < m) return false;
    else {
        for (int i = 0;i < n;i++) {
            if (A[i] > B[i]) {
                return true;
            }
            else if (A[i] < B[i]) {
                return false;
            }
        }
        return false;
    }
}

string Delete(string A, int k) {
    return A.substr(0,k) + A.substr(k+1,A.length());
}

void check(string &A) {
    while (A[0] == '0') {
        A = A.substr(1,A.length());
    }
}

string DeleteDigits(string &A, int k) {
    while (k > 0) {
        string min_string = Delete(A,0);
        for (int i = 1;i < A.length();i++) {
            string temp = Delete(A,i);
            if (compare(min_string,temp)) {
                min_string = temp;
            }
        }
        A = min_string;
        k --;
    }
    check(A);
    return A;
}

int main() {
    //cout << Delete("123456",3) << endl;
    string a = "18728490081378924794978133901201029120111111292221983981398198391";
    cout << DeleteDigits(a,14) << endl;
    return 0;
}
