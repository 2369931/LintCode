#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <map>
#include <algorithm>

using namespace std;

//O(n^2)
/*vector<int> subarraySumClosest(vector<int> &nums) {
    int n = nums.size();
    int min_sum = INT_MAX;
    vector<int> result;
    int start = 0;
    int end = 0;
    if (n == 0) return result;
    for (int i = 0;i < n;i++) {
        int sum = 0;
        for (int j = i;j < n;j++) {
            sum += nums[j];
            if (sum == 0) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
            if (abs(sum) < min_sum) {
                start = i;
                end = j;
                min_sum = abs(sum);
            }
        }
    }
    result.push_back(start);
    result.push_back(end);
    return result;
}*/

vector<int> subarraySumClosest(vector<int> &nums) {
    vector<pair<int,int> > sum;
    int temp = 0;
    sum.push_back(make_pair(temp,-1));
    for(int i=0;i<nums.size();i++)
    {
        temp+=nums[i];
        sum.push_back(make_pair(temp,i));
    }
    sort(sum.begin(),sum.end());
    int start,end;
    int diff = INT_MAX;
    for(int i=1;i<sum.size();i++)
    {
        if(abs(sum[i].first-sum[i-1].first)<=diff)
        {
            diff = abs(sum[i].first-sum[i-1].first);
            start = min(sum[i].second,sum[i-1].second)+1;
            end = max(sum[i].second,sum[i-1].second);
        }
    }
    vector<int> ret;
    ret.push_back(start);
    ret.push_back(end);
    return ret;
}

int main() {
}
