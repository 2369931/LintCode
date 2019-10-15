#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;
/*
///time limit
int lengthOfLongestSubstringKDistinct(string &s, int k) {
    int length = s.length();
    if (length == 0 || k == 0) {
        return 0;
    }
    int result_max = 0;
    for (int j = 0;j < length;j++) {
        int dp[length - j];
        map<char,int> record;
        map<char,int>::iterator it;
        for (int i = j;i < length;i++) {
            it = record.find(s[i]);
            if (it == record.end()) {
                record[s[i]] = 1;
                if (i - j == 0)
                    dp[i-j] = 1;
                else
                    dp[i-j] = dp[i-j-1] + 1;
            }
            else {
                dp[i-j] = dp[i-j-1];
            }
        }
        int result = 0;
        for (int i = 0;i < length-j;i++) {
            if (dp[i] <= k) {
                result = i + 1;
            }
            else {
                break;
            }
        }
        if (result > result_max)
            result_max = result;
    }
    return result_max;
}
*/

int lengthOfLongestSubstringKDistinct(string &s, int k) {
    // write your code here
    if (s.empty())
        return 0;
    int left = 0, res = 0;//left表示最多有k个不同字符子串的起始位置,res表示符合条件的子串的最大长度
    map<char, int> m;//存放字符与其目前出现的最大位置
    //当m中多于k个不同的字符时,若left就是s[left]目前出现的最大位置,
    //在m中直接删除s[left],否则left后移
    for (int i = 0; i < s.size(); ++i)
    {
        m[s[i]] = i;
        while (m.size()>k)
        {
            if (m[s[left]] == left)
                m.erase(s[left]);
            ++left;
        }
        res = max(res, i - left + 1);
    }
    return res;
}

int main()
{
    string s = "eqgkcwGFvjjmxutystqdfhuMblWbylgjxsxgnoh";
    //string s = "beee";
    cout << lengthOfLongestSubstringKDistinct(s, 16) << endl;
    return 0;
}
