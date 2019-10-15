#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int partion(vector<int> &nums,int p,int r) {
    int x = nums[r];
    int i = p - 1;
    int temp = 0;
    for (int j = p;j < r;j ++) {
        if (nums[j] > x) {
            temp = nums[j];
            i = i + 1;
            nums[j] = nums[i];
            nums[i] = temp;
        }
    }
    temp = nums[i+1];
    nums[i+1] = nums[r];
    nums[r] = temp;
    return i+1;
}

int random_partion(vector<int> &nums,int p,int r) {
    srand((int)time(0));
    int x = rand()%(r-p+1) + p;
    int temp = nums[r];
    nums[r] = nums[x];
    nums[x] = temp;
    return partion(nums,p,r);
}

int random_select(vector<int> &nums,int p,int r,int i) {
    int q = random_partion(nums,p,r);
    int k = q - p + 1;
    if (i == k) {
        return nums[q];
    }
    else if (i < k) {
        return random_select(nums,p,q-1,i);
    }
    else {
        return random_select(nums,q+1,r,i-k);
    }
}

int median(vector<int> &nums) {
    int n = nums.size();
    if (n % 2 == 0) {
        return random_select(nums, 0, n-1, n/2 + 1);
    }
    else {
        return random_select(nums, 0, n-1, (n+1)/2);
    }
}

vector<int> medianII(vector<int> &nums) {
    vector<int> new_nums;
    vector<int> result;
    for (int i = 0;i < nums.size();i++) {
        new_nums.push_back(nums[i]);
        result.push_back(median(new_nums));
    }
    return result;
}

int main() {
    int a[7] = {4, 5, 1, 3, 2, 6, 0};
    vector<int> test(a,a+7);
    vector<int> result = medianII(test);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    return 0;
}
