#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
    // write your code here
    vector<string> res;
    string str;
    if (isBreak(s,wordDict))
        findWord(s, wordDict, 1, str,res);
    for (auto &c : res)
    {
        c.pop_back();
    }
    return res;
}

void findWord(string &s, unordered_set<string> &wordDict,int len,string &str,vector<string> &res)
{
    if (s.size()==0)
    {
        res.push_back(str);
    }
    else
    {
        for (int i = len; i <= s.size(); ++i)
        {
            if (wordDict.find(s.substr(0, i)) != wordDict.end())
            {
                string nstr = s.substr(i);
                string mstr = str;
                str += (s.substr(0, i) + " ");
                findWord(nstr, wordDict, 1, str,res);
                str = mstr;
            }
        }
    }
}

bool isBreak(string &s, unordered_set<string> &wordDict)
{
    int len = s.size();
    vector<bool> dp(len + 1, false);
    dp[0] = true;
    for (int i = 1; i <= len; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (dp[j] && (wordDict.find(s.substr(j, i-j)) != wordDict.end()))
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[len];
}

int main() {
    return 0;
}
