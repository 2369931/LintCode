#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isStrobogrammatic(string &num) {
    int n = num.length();
    if (n == 0) {
        return true;
    }
    map<char,char> record;
    record['0'] = '0';
    record['1'] = '1';
    record['2'] = '#';
    record['3'] = '#';
    record['4'] = '#';
    record['5'] = '#';
    record['6'] = '9';
    record['7'] = '#';
    record['8'] = '8';
    record['9'] = '6';
    string change_num = "";
    for (int i = n-1;i >= 0;i--) {
        change_num += record[num[i]];
    }
    cout << change_num << endl;
    return num == change_num;
}

int main() {
    cout << isStrobogrammatic(str) << endl;
    return 0;
}
