#include <iostream>
#include <vector>
#include <map>

using namespace std;

int findDuplicate(vector<int> &nums) {
    int n = nums.size();
    int record[n+1] = {0};
    for (int i = 0;i < n;i++) {
        if (record[nums[i]] == 0) {
            record[nums[i]] += 1;
        }
        else {
            return nums[i];
        }
    }

}

int findDuplicate(vector<int> &nums) {
    int n = nums.size();
    int slow = 0;
    int fast = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);
    fast = 0;
    while (fast != slow) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return fast;
}

int main() {

}
