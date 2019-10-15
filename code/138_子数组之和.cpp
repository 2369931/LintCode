#include <iostream>
#include <vector>

using namespace std;

vector<int> subarraySum(vector<int> &nums) {
    int n = nums.size();
    vector<int> result;
    if (n == 0) return result;
    for (int i = 0;i < n;i++) {
        result.clear();
        result.push_back(i);
        int sum = nums[i];
        for (int j = i+1;j < n;j++) {
            sum += nums[j];
            if (sum == 0) {
                result.push_back(j);
                return result;
            }
        }
    }
}


int main() {
}

