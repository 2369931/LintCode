#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Bucket {
public:
    int low;
    int high;
    Bucket () {
        low = -1;
        high = -1;
    }
};

int maximumGap(vector<int> &nums) {
    int n = nums.size();
    if (n < 2) {
        return 0;
    }
    int max_value = INT_MIN;
    int min_value = INT_MAX;
    vector<Bucket> bucket;
    for (int i = 0;i < n;i ++) {
        if (nums[i] > max_value) {
            max_value = nums[i];
        }
        if (nums[i] < min_value) {
            min_value = nums[i];
        }
    }

    for (int i = 0;i <= n;i ++) {
        Bucket b;
        bucket.push_back(b);
    }
    //cout << 1 << endl;
    double interval;
    if (max_value != min_value)
        interval = (double)n/(max_value - min_value);
    else
        interval = 0;

    for (int i = 0;i < n;i ++) {
        int index = (int)((nums[i] - min_value) * interval);
        //cout << index << endl;
        if (bucket[index].low == -1) {
            bucket[index].low = nums[i];
            bucket[index].high = nums[i];
        }
        else {
            bucket[index].low = min (nums[i],bucket[index].low);
            bucket[index].high = max (nums[i],bucket[index].high);
        }
    }

    int result = bucket[0].high - bucket[0].low;
    int temp = bucket[0].high;
    for (int i = 1;i <= n;i ++) {
        if (bucket[i].low != -1) {
            result = max(result,bucket[i].low - temp);
            temp = bucket[i].high;
        }
    }
    return result;
}

int main() {
    int a[10] = {999,999,999,999,999,999,999,999,999,999};
    vector<int> test(a,a+10);
    cout << maximumGap(test) << endl;
    return 0;
}
