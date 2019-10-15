#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define MAX 1000
using namespace std;

/***************************************************************************************/
/***************************************************************************************/

/*(1)采用循环
最长回文子序列 （不连续地---序列，子串是连续地）
动态规划
**/
int maxPalindromeLen(string s){
    int len = s.length();
    if (len == 0)
    {
        return 0;
    }
    else if (len == 1)
    {
        return 1;
    }
    vector<int> max_Palind(len);
    //init
    for (size_t i = 0; i < len; i++)
    {
        max_Palind[i] = 0;
    }
    max_Palind[0] = 1;

    for (int j = 0; j < len; j++)
    {
        for (int i = 0; i <j; ++i)
        {
            if (max_Palind[i]<max_Palind[i + 1] + (s[i] == s[j]) * 2){
                max_Palind[i] = max_Palind[i + 1] + (s[i] == s[j]) * 2;
            }
        }
        max_Palind[j] = 1;
    }
    return max_Palind[0];
}

/***************************************************************************************/
/***************************************************************************************/
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }

}

int lps(string &s, int i, int j)
{
    if (i == j)
    {
        return 1;
    }
    if (i > j)
    {
        return 0;
    }
    //如果首尾相同
    if (s[i] == s[j])
    {
        return lps(s, i + 1, j - 1) + 2;
    }
    //首尾不同，两种情况
    return max(lps(s, i + 1, j), lps(s, i, j - 1));
}

int main() {
    int a[5] = {2,1,3,5,4};
    vector<int> test(a,a+5);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << " ";
    }
    cout << endl;
    string str = "1211";
    cout << maxPalindromeLen(str) << endl;
    cout << lps(str,0,str.size()-1) << endl;
    return 0;
}
