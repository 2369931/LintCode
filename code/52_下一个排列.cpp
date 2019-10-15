
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> previousPermuation(vector<int> &nums) {
    if (nums.size() == 1) {
        return nums;
    }
    else if (next_permutation(nums.begin(),nums.end())) {
        return nums;
    }
    else {
        vector<int> result = nums;
        //prev_permutation(nums.begin(),nums.end());
        while (prev_permutation(nums.begin(),nums.end())) {
            result = nums;
        }
        return result;
    }
}

int main() {
    int a[] = {1,2,3,4};
    vector<int> test(a,a+4);
    vector<int> result = previousPermuation(test);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
