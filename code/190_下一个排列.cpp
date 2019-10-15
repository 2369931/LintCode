#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums) {
    //next_permutation(nums.begin(),nums.end());
    int size = nums.size(), i = 0, j = 0;
        if(size == 0) {
            return;
        }
        for(i=size-1; i>=0; i--)  {
            for(j=size-1; j>i; j--) {
                if(nums[i]<nums[j])  {
                    swap(nums[i],nums[j]);
                    sort(nums.begin()+i+1,nums.end());
                    return;
                }
            }
        }
        sort(nums.begin(),nums.end());
}

int main() {
    int a[6] = {1,4,6,5,2,1};
    vector<int> test(a,a+6);
    nextPermutation(test);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << " ";
    }
    return 0;
}
