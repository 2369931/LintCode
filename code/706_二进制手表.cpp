#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string intToString(int num) {
    stringstream ss;
    ss << num;
    string res = "";
    ss >> res;
    return res;
}

int find_1(int num) {
    int res = 0;
    while(num) {
        num = num & (num - 1);
        res ++;
    }
    return res;
}

vector<string> binaryTime(int num) {
    vector<string> res;
    if (num < 0) {
        return res;
    }
    map<int,int> dict;
    for (int i = 0;i < 60;i++) {
        dict[i] = find_1(i);
    }
    for (int i = 0;i < 12; i++) {
        for (int j = 0;j < 60;j ++) {
            if (dict[i] + dict[j] == num) {
                string temp = intToString(i) + ":";
                if (j < 10) {
                    temp = temp + "0" + intToString(j);
                }
                else {
                    temp += intToString(j);
                }
                res.push_back(temp);
            }
        }
    }
    return res;
}

int main(){
    vector<string> res = binaryTime(2);
    for (int i = 0;i < res.size();i++)
        cout << res[i] << " ";
    return 0;
}
