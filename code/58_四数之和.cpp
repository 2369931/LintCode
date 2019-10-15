#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > fourSum(vector<int> &numbers, int target) {
    vector<vector<int> > result;
    int n = numbers.size();
    sort(numbers.begin(),numbers.end());
    for (int i = 0;i < n;i++) {
        if (i > 0 && numbers[i] == numbers[i-1]) continue;
        for (int l = i + 1;l < n;l++) {
            if (l > i+1 && numbers[l] == numbers[l-1]) continue;
            int j = l + 1;
            int k = n - 1;
            while (j < k) {
                if (j > l+1 && numbers[j] == numbers[j-1]) {
                    j++;
                    continue;
                }
                else if (k < n-1 && numbers[k] == numbers[k+1]) {
                    k--;
                    continue;
                }
                //cout << i << " : "  << l << " : " << j << " : " << k << endl;
                int sum = numbers[i] + numbers[l] + numbers[j] + numbers[k];
                if (sum == target) {
                    vector<int> temp;
                    temp.push_back(numbers[i]);
                    temp.push_back(numbers[l]);
                    temp.push_back(numbers[j]);
                    temp.push_back(numbers[k]);
                    result.push_back(temp);
                    j++;
                }
                else if (sum < target) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
    }
    return result;
}

int main() {
    int a[6] = {1,0,-1,0,2,-2};
    vector<int> test(a,a+6);
    vector<vector<int> > result = fourSum(test,0);
    for (int i = 0;i < result.size();i ++) {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << " " << result[i][3] << endl;
    }
    return 0;
}
