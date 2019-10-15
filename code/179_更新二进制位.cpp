#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void add(vector<int>& nums) {
    for (int i = 1;i < nums.size();i++) {
        if (nums[i] == 1) nums[i] = 0;
        else nums[i] = 1;
    }
    int n = nums.size() - 1;
    if (nums[n] == 0) {
        nums[n] = 1;
    }
    else {
        nums[n] = 0;
        int flag = 1;
        for (int i = nums.size()-2;i >= 1;i--) {
            int temp = flag + nums[i];
            if (temp <= 1) {
                nums[i] = temp;
                break;
            }
            else {
                nums[i] = 0;
                flag = 1;
                continue;
            }
        }
    }
}

vector<int> change(int num) {
    vector<int> result;
    int flag = 0;
    if (num < 0) {
        flag = 1;
        num = -num;
    }
    while (num != 0) {
        result.insert(result.begin(),num%2);
        num = num / 2;
    }
    if (flag == 1) {
        while (result.size() != 32) {
            result.insert(result.begin(),0);
        }
        result[0] = 1;
        add(result);
    }
    return result;
}

int change_back(vector<int> nums) {
    int flag = 1;
    if (nums[0] == 1 && nums.size() == 32) {
        flag = -1;
        add(nums);
    }
    int n = nums.size() - 1;
    long long result = 0;
    for (int i = 1;i <= n;i++) {
        if (nums[i] == 1) {
            result += pow(2, n - i);
        }

    }
    return (int)(result * flag);
}

int updateBits(int n, int m, int i, int j) {
    if (n == 0) return 0;
    vector<int> v_n = change(n);
    while (v_n.size() != 32) {
        v_n.insert(v_n.begin(),0);
    }
    int length = v_n.size();
    vector<int> v_m = change(m);
    while (v_m.size() < j-i+1) {
        v_m.insert(v_m.begin(),0);
    }
    int k = 0;
    int l = length - j - 1;
    for (int p = i;p <= j;p++) {
        v_n[l] = v_m[k];
        l++;
        k++;
    }
    return change_back(v_n);
}

int main() {
    /*vector<int> result = change(-8);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    cout << change_back(result) << endl;*/
    cout << updateBits(-11,-789,0,31) << endl;
    return 0;
}
