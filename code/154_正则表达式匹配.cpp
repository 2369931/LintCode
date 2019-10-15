#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

bool sub(int ls, int lp, int ps, int pp, string &s, string &p)
{
    while(ps < ls && pp < lp) {
        int c = p[pp];
        if(c == '*') { //处理*
            char pre = p[pp - 1];
            ++pp;
            if(sub(ls, lp, ps, pp, s, p)) return true;
            for(; ps < ls; ++ps) {
                if(pre == '.' || pre == s[ps]) {
                    if(sub(ls, lp, ps + 1, pp, s, p)) return true;
                }else {
                    return false;
                }
                //++ps;
            }
            return false;
        }
        else if(pp + 1 >= lp || p[pp + 1] != '*') { //处理单个字符
            if(c != '.' && c != s[ps]) {
                return false;
            }else {
                ++pp;
                ++ps;
            }
        }
        else { //后面跟*的单个字符则跳过
            ++pp;
        }
    }
    if(ps == ls && pp == lp) {
        return true;
    }else {
        return false;
    }
}

bool isMatch(string &s, string &p) {
    // write your code here
    int ls = s.length();
    int lp = p.length();
    return sub(ls, lp, 0, 0, s, p);
}

int main() {
    string s = "a";
    string p = "*";
    cout << isMatch(s, p) << endl;
    return 0;
}
