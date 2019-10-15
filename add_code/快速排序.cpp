#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int mypartition(vector<int> &nums, int p, int r) {
    int x = nums[r];
    int i = p - 1;
    for (int j = p;j < r;j++) {
        if (nums[j] <= x) {
            i ++;
            swap(nums,i,j);
        }
    }
    i += 1;
    swap(nums,i,r);
    return i;
}

void quicksort(vector<int> &nums, int p, int r) {
    if (p < r) {
        int q = mypartition(nums,p,r);
        quicksort(nums,p,q-1);
        quicksort(nums,q+1,r);
    }
}

int main() {
    int a[5] = {2,1,3,5,4};
    vector<int> test(a,a+5);
    quicksort(test,0,test.size()-1);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << " ";
    }
    return 0;
}
