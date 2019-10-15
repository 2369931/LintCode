#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

string int_to_str(int num) {
    stringstream ss;
    ss << num;
    string str;
    ss >> str;
    ss.clear();
    return str;
}

string compress(string &originalString) {
    string result = "";
    if (originalString.length() == 0 || originalString.length() == 1) return originalString;
    char temp = originalString[0];
    int count = 1;
    for (int i = 1;i < originalString.length();i++) {
        if (originalString[i] != temp) {
            result += temp;
            temp = originalString[i];
            result += int_to_str(count);
            count = 1;
        }
        else {
            count ++;
        }
    }
    result += temp + int_to_str(count);
    if (result.size() < originalString.size())
        return result;
    else
        return originalString;
}

int main() {
    string s = "a";
    cout << compress(s) << endl;
    return 0;
}
