#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void swap (string &s, int i, int j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

string get_reverse(string s) {
    string str = "";
    for (int i = s.length() - 1;i >= 0;i--) {
        str += s[i];
    }
    return str;
}

string get_next_permutation(string &s) {
    int index = 0;
    for (int i = s.length() - 1;i > 0;i--) {
        if (s[i-1] < s[i]) {
            index = i - 1;
            break;
        }
    }
    char temp_min = '9';
    int min_index = index;
    for (int i = index+1;i < s.length();i++) {
        if (s[i] > s[index] && s[i] < temp_min) {
            temp_min = s[i];
            min_index = i;
        }
    }
    swap(s,index,min_index);
    string result = "";
    for (int i = 0;i <= index;i++) {
        result += s[i];
    }
    string str = "";
    for (int i = index + 1;i < s.length();i++) {
        str += s[i];
    }
    result  = result + get_reverse(str);
    s = result;
    return result;
}

string getPermutation(int n, int k) {
    string result = "";
    if (n == 0) {
        return result;
    }
    else {
        string s = "";
        char temp = '1';
        for (int i = 0;i < n;i++) {
            s += temp;
            temp ++;
        }
        if (n == 1 || k == 1) {
            return s;
        }
        for (int i = 0;i < k-1; i++) {
            result = get_next_permutation(s);
        }
    }
    return result;
}

int main() {
    cout << getPermutation(3,4) << endl;
    return 0;
}
