#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
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

int kthLargestElement(int n, vector<int> &nums) {
    // write your code here
    int p = 0;
    int r = nums.size() - 1;
    return random_select(nums,p,r,n);
}

int main() {
    int a[10] = {1,2,3,4,5,6,7,100,200,1000};
    vector<int> num(a,a+10);
    cout << kthLargestElement(6,num) << endl;
    return 0;
}
