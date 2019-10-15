#include <iostream>
#include <vector>

using namespace std;

vector<int> continuousSubarraySum(vector<int> &A) {
    int n = A.size();
    vector<int> result;
    if (n == 0) {
        return result;
    }
    int sum = 0;
    int max_sum = INT_MIN;
    int start = 0;
    int end = -1;
    int record_start = start;
    for (int i = 0;i < n;i++) {
        sum += A[i];
        if (max_sum < sum) {
            max_sum = sum;
            record_start = start;
            end = i;
        }
        if (sum < 0) {
            sum = 0;
            start = i+1;
        }
    }
    result.push_back(record_start);
    result.push_back(end);
    return result;
}

int main() {
    int a[6] = {-2,-1,-1,-1,-1,-1};
    vector<int> test(a,a+6);
    vector<int> result = continuousSubarraySum(test);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
