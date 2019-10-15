#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isUnique(string &str) {
    map<char,int> record;
    for (int i = 0;i < str.length();i++) {
        map<char,int>::iterator it;
        it = record.find(str[i]);
        if (it == record.end()) {
            record[str[i]] = 0;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    string s = "aaa";
    cout << isUnique(s) << endl;
    return 0;
}
