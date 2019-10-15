#include <iostream>
#include <string>
#include <map>

using namespace std;

int firstUniqChar(string &s) {
    int n = s.length();
    if (n == 0) {
        return -1;
    }
    map<char,int> record;
    for (int i = 0;i < n;i++) {
        map<char,int>::iterator it = record.find(s[i]);
        if (it == record.end()) {
            record[s[i]] = 1;
        }
        else {
            record[s[i]] += 1;
        }
    }
    for (int i = 0;i < n;i++) {
        if (record[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {

}
