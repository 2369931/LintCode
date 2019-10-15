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
    int left = 0, res = 0;//left��ʾ�����k����ͬ�ַ��Ӵ�����ʼλ��,res��ʾ�����������Ӵ�����󳤶�
    map<char, int> m;//����ַ�����Ŀǰ���ֵ����λ��
    //��m�ж���k����ͬ���ַ�ʱ,��left����s[left]Ŀǰ���ֵ����λ��,
    //��m��ֱ��ɾ��s[left],����left����
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
