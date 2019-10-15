#include <iostream>
#include <vector>

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
    while (result.size() != 32) {
            result.insert(result.begin(),0);
    }
    if (flag == 1) {
        result[0] = 1;
        add(result);
    }
    return result;
}

int bitSwapRequired(int a, int b) {
    int result = 0;
    vector<int> v_a = change(a);
    vector<int> v_b = change(b);
    for (int i = 0;i < 32;i++) {
        if (v_a[i] != v_b[i]) {
            result ++;
        }
    }
    return result;
}

int main() {
    cout << bitSwapRequired() << endl;
    return 0;
};
