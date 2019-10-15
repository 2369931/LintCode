#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> &numbers, int target) {
    int result = -999999;
    int n = numbers.size();
    sort(numbers.begin(),numbers.end());
    for (int i = 0;i < n;i++) {
        if (i > 0 && numbers[i] == numbers[i-1]) continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            if (j > i+1 && numbers[j] == numbers[j-1]) {
                j++;
                continue;
            }
            else if (k < n-1 && numbers[k] == numbers[k+1]) {
                k--;
                continue;
            }
            //cout << i << " : " << j << " : " << k << endl;
            int sum = numbers[i] + numbers[j] + numbers[k];
            if (abs(sum - target) < abs(result - target)) {
                result = sum;
            }
            if (sum < target) {
                j++;
            }
            else {
                k--;
            }
        }
    }
    return result;
}

int main() {
    int a[4] = {-1,2,1,-4};
    vector<int> test(a,a+4);
    int result = threeSumClosest(test,1);
    /*for (int i = 0;i < result.size();i ++) {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << " " << endl;
    }*/
    cout << result << endl;
    return 0;
}
