#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int stringToInt(string str) {
    stringstream ss;
    ss << str;
    int res = 0;
    ss >> res;
    return res;
}

string intToString(int str) {
    stringstream ss;
    ss << str;
    string res = "";
    ss >> res;
    return res;
}

string reverseString(string str) {
    string res = "";
    for (int i = str.length()-1;i >= 0;i--) {
        res += str[i];
    }
    return res;
}

bool judge(string str) {
    int n = stringToInt(str);
    if (n <= 21) {
            return false;
    }
    else {
        //根据范围使用大数加法
        for (int i = 11;i <= n/2;i++) {
            if (i + stringToInt(reverseString(intToString(i))) == n) {
                //cout << i << " :: " << reverseString(intToString(i)) << endl;
                return true;
            }
        }
    }

}

int reverseNumber(vector<string> nums) {
    int res = 0;
    int n = nums.size();
    if (n == 0) {
        return res;
    }
    for (int i = 0;i < n;i++) {
        if (judge(nums[i])) {
            res ++;
        }
    }
    return res;
}

int main() {
    string a[2] = {"22", "121"};
    vector<string> test(a,a+2);
    cout << reverseNumber(test) << endl;
    return 0;
}
