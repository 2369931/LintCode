#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int StringToInt(string str) {
    stringstream ss;
    int res;
    ss << str;
    ss >> res;
    return res;
}

string IntToString(int value) {
    stringstream ss;
    string res = "";
    ss << value;
    ss >> res;
    return res;
}

string encode(vector<string> &strs) {
    int n = strs.size();
    string res = "";
    if (n == 0) {
        return res;
    }
    for (int i = 0;i < n;i++) {
        res = res + "#" + IntToString(strs[i].length()) + "#" + strs[i];
    }
    return res;
}

vector<string> decode(string &str) {
    vector<string> res;
    int n = str.length();
    if (n == 0) {
        return res;
    }
    int i = 0;
    while (i < n) {
        if (str[i] == '#') {
            int j = i+1;
            while (str[j] != '#') {
                j ++;
            }
            int number = StringToInt(str.substr(i+1,j-i-1));
            string temp = str.substr(j+1,number);
            i = j + number + 1;
            res.push_back(temp);
            cout << number << endl;
        }
    }
    return res;
}

int main() {
    string a[4] = {"lint","code","","you"};
    vector<string> test(a,a+4);
    string en_code = encode(test);
    cout << en_code << endl;
    vector<string> res = decode(en_code);
    for (int i = 0;i < res.size();i++) {
        cout << res[i] << " ";
    }
    return 0;
}
