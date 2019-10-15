#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <sstream>
#include <stdio.h>

using namespace std;

int romanToInt(string &s) {
    int n = s.length();
    if (n == 0) {
        return -1;
    }
    map<char,int> record;
    record['I'] = 1;
    record['V'] = 5;
    record['X'] = 10;
    record['L'] = 50;
    record['C'] = 100;
    record['D'] = 500;
    record['M'] = 1000;
    int result = 0;
    int temp = 0;
    int value = 0;
    for (int i = n-1;i >= 0;i--) {
        value = record[s[i]];
        if (value >= temp) {
            result += value;
        }
        else {
            result -= value;
        }
        temp = value;
    }
    return result;
}

int main() {
    string test = "XCIX";
    cout << romanToInt(test) << endl;
    return 0;
}
