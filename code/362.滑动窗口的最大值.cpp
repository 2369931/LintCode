#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

void print(vector<int> A) {
    for (int i = 0;i < A.size();i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
/*TLE
int find_index (vector<int> A, int target) {
    int start = 0;
    int end = A.size()-1;
    while(start <= end) {
        int mid = (start + end)/2;
        if (A[mid] == target) {
            return mid;
        }
        else if(A[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
}

void insert_index (vector<int>& A, int target) {
    int n = A.size();
    if (target <= A[0]) {
        A.insert(A.begin(),target);
        return;
    }
    else if (target >= A[n-1]) {
        A.insert(A.end(),target);
        return;
    }
    else {
        for (int i = 0;i < n;i++) {
            if (target <= A[i]) {
                A.insert(A.begin() + i,target);
                return;
            }
        }
    }
}

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    int n = nums.size();
    if (n == 0 || k == 0 || n < k)
        return result;
    vector<int> temp;
    for (int i = 0;i < k;i++) {
        temp.push_back(nums[i]);
    }
    sort(temp.begin(), temp.end());
    result.push_back(temp[k-1]);
    //int max_value = temp[k-1];
    for (int i = k;i < n;i++) {
        int in = nums[i];
        int out = nums[i-k];
        int index = find_index(temp, out);
        temp.erase(temp.begin()+index);
        insert_index(temp, in);
        result.push_back(temp[k-1]);
    }
    return result;
}
*/

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    int n = nums.size();
    if (n == 0 || k == 0 || n < k)
        return result;
    deque<int> q;
    for (int i = 0;i < k;i++) {
        while(!q.empty()&&nums[q.back()] <= nums[i])
            q.pop_back();
        q.push_back(i);
    }
    result.push_back(nums[q.front()]);
    for (int i = k, left = 1;i < n;i++, left++) {
        while(!q.empty()&&nums[q.back()] <= nums[i])
            q.pop_back();
        q.push_back(i);
        while(left > q.front()) {
            q.pop_front();
        }
        result.push_back(nums[q.front()]);
    }
    return result;
}
int main() {
    int a[9] = {1,2,7,7,2,10,3,4,5};
    vector<int> test(a,a+9);
    //cout << find_index(test,5) << endl;
    //insert_index(test,0);
    vector<int> result = maxSlidingWindow(test, 2);
    cout << endl;
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    return 0;
}

