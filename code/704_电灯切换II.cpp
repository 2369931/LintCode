#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

string switch_a(string str) {
    string res = "";
    for (long long i = 0;i < str.length();i++) {
        if (str[i] == '0') {
            res += '1';
        }
        else {
            res += '0';
        }
    }
    return res;
}

string switch_b(string str) {
    string res = "";
    for (long long i = 0;i < str.length();i++) {
        if ((i+1) % 2 == 0) {
            if (str[i] == '0') {
                res += '1';
            }
            else {
                res += '0';
            }
        }
        else {
            res += str[i];
        }
    }
    return res;
}

string switch_c(string str) {
    string res = "";
    for (long long i = 0;i < str.length();i++) {
        if ((i+1) % 2 == 1) {
            if (str[i] == '0') {
                res += '1';
            }
            else {
                res += '0';
            }
        }
        else {
            res += str[i];
        }
    }
    return res;
}

string switch_d(string str) {
    string res = str;
    for (long long i = 0;3*i < str.length();i++) {
        long long k = 3*i;
        if (str[k] == '0') {
            res[k] = '1';
        }
        else {
            res[k] = '0';
        }
    }
    return res;
}

void dp(map<string,int> & dict, map<int, set<string> > & record, string str, int number ,int m) {
    if (number > m) {
        return;
    }
    if (record.find(number) == record.end()) {
        set<string> temp;
        record[number] = temp;
    }
    if (record[number].find(str) == record[number].end()) {
        record[number].insert(str);
    }
    else {
        return;
    }
    dp(dict,record,switch_a(str),number+1,m);
    dp(dict,record,switch_b(str),number+1,m);
    dp(dict,record,switch_c(str),number+1,m);
    dp(dict,record,switch_d(str),number+1,m);
    if (dict.find(str) == dict.end() && number == m) {
        dict[str] = 1;
    }
}

int flipLights(int n, int m) {
    if (n <= 0 || m <= 0) {
        return 1;
    }
    map<string,int> dict;
    map<int, set<string> > record;
    string init = "";
    for (int i = 0;i < n;i++) {
        init += '1';
    }
    /*for (int i = 0;i <= m;i++) {
        set<string> temp;
        record[i] = temp;
    }*/
    int number = 0;
    dp(dict,record,init,number,m);
    return dict.size();
}

/*
int flipLights (int n, int m) {
 if(n==0){
        return 0;
    }
    if(m==0){
        return 1;
    }
    if(n==1){
        return 2;
    }
    if(n==2){
        if(m==1){
            return 3;
        }
        return 4;
    }
    if(m==1){
        return 4;
    }
    if(m==2){
        return 7;
    }
    return 8;
}
*/

int main() {
    //string a = "1010";
    cout << flipLights(2147483647,30) << endl;
    return 0;
}
