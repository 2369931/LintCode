#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums) {
    int num = 0;
    for (vector<int>::iterator it = nums.begin();it != nums.end();) {
        if (*it == 0) {
            it = nums.erase(it);
            num ++;
        }
        else {
            it ++;
        }
    }
    for (int i = 0;i < num;i++) {
        nums.push_back(0);
    }
}

int main() {
    int a[5] = {0,0,0,3,1};
    vector<int> test(a,a+5);
    moveZeroes(test);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << " ";
    }
    return 0;
}
