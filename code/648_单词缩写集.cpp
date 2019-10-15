#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class ValidWordAbbr {
public:
map<string, int> dic;
map<string, int> record;
ValidWordAbbr(vector<string> dictionary) {
    int n = dictionary.size();
    if (n != 0) {
        for (int i = 0;i < n;i ++) {
            int m = dictionary[i].size();
            string str = "";
            if (m <= 2) {
                str = dictionary[i];
            }
            else {
                str = dictionary[i][0] + to_string(m-2) + dictionary[i][m-1];
            }
            dic[dictionary[i]] = 1;
            record[str] = 1;
        }
    }
}

bool isUnique(string &word) {
    int m = word.size();
    string str = "";
    if (m <= 2) {
        str = word;
    }
    else {
        str = word[0] + to_string(m-2) + word[m-1];
    }
    map<string, int>::iterator itt = dic.find(word);
    if (itt != dic.end()) {
        return true;
    }
    else {
        map<string, int>::iterator it = record.find(str);
        if (it == record.end()) {
            return true;
        }
        else {
            return false;
        }
    }
}
};

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto a : dictionary) {
            string k = a[0] + to_string(a.size() - 2) + a.back();
            m[k].insert(a);
        }
    }
    bool isUnique(string word) {
        string k = word[0] + to_string(word.size() - 2) + word.back();
        return m[k].count(word) == m[k].size();
    }
private:
    unordered_map<string, set<string>> m;
};
