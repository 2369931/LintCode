#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits) {
    int n = digits.size();
    vector<int> result;
    if (n == 0) {
        return result;
    }
    int flag = 0;
    int temp = 0;
    for (int i = n-1;i >= 0;i--) {
        if (i == n-1)
            temp = digits[i] + flag + 1;
        else
            temp = digits[i] + flag;
        if (temp >= 10) {
            temp %= 10;
            flag = 1;
        }
        else {
            flag = 0;
        }
    result.insert(result.begin(),temp);
    }
    if (flag == 1) {
        result.insert(result.begin(),1);
    }
    return result;
}
