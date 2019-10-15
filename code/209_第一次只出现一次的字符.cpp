#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

char firstUniqChar(string &str) {
    map<char, int> record;
    for (int i = 0;i < str.length();i++) {
        record[str[i]] ++;
    }
    map<char, int>::iterator it;
    for (it = record.begin();it != record.end();it++) {
        if (it->second == 1) {
            return it->first;
        }
    }
}



