#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int stringToint (string str) {
    stringstream ss;
    ss << str;
    int result;
    ss >> result;
    ss.clear();
    return result;
}

string intTostring (int temp) {
    stringstream ss;
    ss << temp;
    string str;
    ss >> str;
    ss.clear();
    return str;
}

bool compare (string a, string b) {
    if (a == b) {
        return false;
    }
    int i = 0;
    int j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] > b[j]) {
            return true;
        }
        else if (a[i] < b[j]) {
            return false;
        }
        else {
            if (i + 1 == a.size() && j + 1 == b.size()) {
                return false;
            }
            if (i + 1 < a.size()) {
                i ++;
            }
            if (j + 1 < b.size()) {
                j ++;
            }
        }
    }
}

string minNumber(vector<int> &nums) {
    string result = "0";
    if (nums.size() == 0) return result;
    vector<string> record;
    for (int i = 0;i < nums.size();i++) {
        record.push_back(intTostring(nums[i]));
    }
    for (int i = 0;i < record.size();i++) {
        for (int j = i+1;j < record.size();j++) {
            if (compare (record[i],record[j])) {
                string temp = record[j];
                record[j] = record[i];
                record[i] = temp;
            }
        }
    }
    result = "";
    for (int i = 0;i < record.size();i++) {
        if (record[i] != "0")
            result += record[i];
    }
    if (result == "")
        result += "0";
    return result;
}

int main() {
    int a[3] = {3,32,321};
    vector<int> test(a,a+3);
    cout << compare("3577","1622") << endl;
    cout << minNumber(test) << endl;
    return 0;
}

