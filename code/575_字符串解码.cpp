#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int strToint(string str) {
    stringstream ss;
    ss << str;
    int result;
    ss >> result;
    return result;
}

int next(string s,int i,int length) {
     int flag = 1;
     int index = -1;
     for (int j = i+length;j < s.length();j++) {
         if (s[j] == '[') {
             flag ++;
         }
         else if (s[j] == ']') {
             flag --;
             if (flag == 1) {
                 index = j;
                 break;
             }
         }
     }
     return index;
}

string expressionExpand(string &s) {
    int n = s.length();
    if (n == 0) {
        return "";
    }
    string res = "";
    for (int i = 0;i < n;i++) {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
            res += s[i];
        }
        else if (s[i] >= '1' && s[i] <= '9') {
            int length = 1;
            int times;
            for (int j = i+1;j < n;j++) {
                if (s[j] >= '0' && s[j] <= '9') {
                    length ++;
                }
                else {
                    break;
                }
            }
            times = strToint(s.substr(i,length));
            int index = next(s,i,length);
            string temp = s.substr(i+length+1,index-i-length-1);
            string str = expressionExpand(temp);
            for (int j = 0;j < times - 1;j++) {
                res += str;
            }
            i = i + length - 1;
        }
        else if (s[i] == '0') {
            i = next(s,i,1);
        }
    }
    return res;
}

int main() {
    string str = "1[lintcode]4[abcAhj]4[wer]0[peer]";
    cout << expressionExpand(str) << endl;
    return 0;
}
