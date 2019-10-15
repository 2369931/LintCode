#include <iostream>
#include <vector>

using namespace std;


int firstBit(int num) {
    int n = 0;
    while((num & 1 == 0) && n < 32) {
        num >> 1;
        n ++;
    }
    return n;
}

bool isIndexBit(int num, int index) {
    num = num >> index;
    return num & 1;
}

vector<int> findTwoNumber(vector<int> & nums) {
    int n = nums.size();
    if (n <= 2) {
        return nums;
    }
    int num = 0;
    for (int i = 0;i < n;i ++) {
        num ^= nums[i];
    }
    int index = firstBit(num);
    int number1 = 0;
    int number2 = 0;
    for (int i = 0;i < n;i ++) {
        if (isIndexBit(nums[i],index)) {
            number1 ^= nums[i];
        }
        else {
            number2 ^= nums[i];
        }
    }
    vector<int> res;
    res.push_back(number1);
    res.push_back(number2);
    return res;
}

int main() {
    int a[6] = {1,2,1,2,3,4};
    vector<int> test(a,a+6);
    vector<int> res = findTwoNumber(test);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
