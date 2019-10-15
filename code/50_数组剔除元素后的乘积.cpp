#include <iostream>
#include <vector>

using namespace std;

/*void record_result(vector<long long> &record,int i, int j) {
}*/
vector<long long> productExcludeItself(vector<int> &nums) {
    vector<long long> result;
     for (int i = 0;i < nums.size();i++) {
        long long temp = 1;
        for (int j = 0;j < nums.size();j++) {
            if (j == i) continue;
            else if (nums[j] == 0) {
                temp = 0;
                break;
            }
            temp *= nums[j];
        }
        result.push_back(temp);
     }
     return result;
}

int main() {
    int a[] = {1,2,3};
    vector<int> test(a,a+3);
    vector<long long> result = productExcludeItself(test);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
