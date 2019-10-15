#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int atoi(string &str) {
    if (str == "") return 0;
    int flag = 0;
    int flag2 = 0;
    vector<int> record;
    for (int i = 0;i < str.length();i++) {
        if (str[i] == ' ') continue;
        else if (str[i] == '-') {
            flag = 1;
            if(record.size() > 0) break;
        }
        else if (str[i] == '+') {
            flag2 = 1;
            if(record.size() > 0) break;
        }
        else if (str[i] == '.') break;
        else if (str[i] >= '0' && str[i] <= '9')
            record.push_back(str[i] - '0');
        else if (str[i] >= 'a' && str[i] <= 'z') break;
        else return 0;
    }
    if (record.size() == 0) return 0;
    else if (flag == 1 && flag2 == 1) return 0;
    else if (record.size() > 10) {
        if (flag == 0) return 2147483647;
        else return -2147483648;
    }
    else {
        long long result = 0;
        for (int i = 0;i < record.size();i++) {
            result += record[i] * pow(10,record.size() - 1 - i);
        }
        if (result > 2147483647) {
            if (flag == 0) return 2147483647;
            else return -2147483648;
        }
        else {
            if (flag == 0) return (int)result;
            else return int(result*-1);
        }
    }
}

int main() {
    string test = "15+4";
    cout << atoi(test) << endl;
    return 0;
}
