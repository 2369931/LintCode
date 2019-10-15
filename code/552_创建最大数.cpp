#include <iostream>
#include <vector>

using namespace std;

vector<int> find_vec(vector<int> num, int k) {
    vector<int> res;
    int m = num.size() - k;
    for (int i = 0;i < num.size();i++) {
        while (m > 0&&res.size() > 0&&res.back() < num[i]) {
            res.pop_back();
            m--;
        }
        res.push_back(num[i]);
    }
    return res;
}

vector<int> merge_vec(vector<int> num1, vector<int> num2) {
    vector<int> result;
    while (!num1.empty() || !num2.empty()) {
        if (num1 > num2) {
            result.push_back(num1[0]);
            num1.erase(num1.begin());
        }
        else {
            result.push_back(num2[0]);
            num2.erase(num2.begin());
        }
    }
    return result;
}

vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> res;
    for (int i = 0;i <= k;i++) {
        if(i>nums1.size() || k-i>nums2.size()) continue;
        vector<int> result = merge_vec(find_vec(nums1,i) , find_vec(nums2,k-i));
        if (result > res) {
            res = result;
        }
    }
    res.resize(k);
    return res;
}

int main() {
    int a[4] = {3,4,6,5};
    int b[6] = {9,1,2,5,8,3};
    vector<int> test_a(a,a+4);
    vector<int> test_b(b,b+6);
    vector<int> res = maxNumber(test_a,test_b,5);
    for(int i = 0;i < 5;i++) {
        cout << res[i] << " ";
    }
    return 0;

}
