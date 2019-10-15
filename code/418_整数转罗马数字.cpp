#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <stdio.h>

using namespace std;

string intToRoman(int n) {
    string result = "";
    if (n < 1 || n > 3999) {
        return result;
    }
    string c[4][10]={
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
        };
    string roman;
    roman.append(c[3][n / 1000 % 10]);
    roman.append(c[2][n / 100 % 10]);
    roman.append(c[1][n / 10 % 10]);
    roman.append(c[0][n % 10]);
    return roman;
}
