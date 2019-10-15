#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <limits>

using namespace std;

void heap_insert(vector<int> &max_heap,vector<int> &min_heap,int temp) {
    int n = max_heap.size();
    int m = min_heap.size();
    int max_heap_top = max_heap[0];
    int min_heap_top = min_heap[0];
    if (temp >= max_heap_top && temp <= min_heap_top) {
        if (n > m) {
            min_heap.push_back(temp);
            push_heap(min_heap.begin(),min_heap.end(),greater<int>());
        }
        else {
            max_heap.push_back(temp);
            push_heap(max_heap.begin(),max_heap.end(),less<int>());
        }
    }
    else if (temp > min_heap_top) {
        if (m > n) {
            max_heap.push_back(min_heap_top);
            push_heap(max_heap.begin(),max_heap.end(),less<int>());
            //min_heap[0] = temp;
            pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
            min_heap.pop_back();
            min_heap.push_back(temp);
            push_heap(min_heap.begin(),min_heap.end(),greater<int>());
        }
        else {
            min_heap.push_back(temp);
            push_heap(min_heap.begin(),min_heap.end(),greater<int>());
        }
    }
    else {
        if (n > m) {
            min_heap.push_back(max_heap_top);
            push_heap(min_heap.begin(),min_heap.end(),greater<int>());
            //max_heap[0] = temp;
            pop_heap(max_heap.begin(), max_heap.end(), less<int>());
            max_heap.pop_back();
            max_heap.push_back(temp);
            push_heap(max_heap.begin(),max_heap.end(),less<int>());
        }
        else {
            max_heap.push_back(temp);
            push_heap(max_heap.begin(),max_heap.end(),less<int>());
        }
    }
}

int media(vector<int> max_heap,vector<int> min_heap) {
    int n = max_heap.size();
    int m = min_heap.size();
    if (n > m) return max_heap[0];
    else if (n < m) return min_heap[0];
    else return max_heap[0];
}

vector<int> medianII(vector<int> &nums) {
    vector<int> max_heap;
    vector<int> min_heap;
    vector<int> result;
    if (nums.size() == 0) {
        return result;
    }
    if (nums.size() == 1) {
        result.push_back(nums[0]);
        return result;
    }
    if (nums[0] > nums[1]) {
        max_heap.push_back(nums[1]);
        min_heap.push_back(nums[0]);
    }
    else {
        max_heap.push_back(nums[0]);
        min_heap.push_back(nums[1]);
    }
    result.push_back(nums[0]);
    result.push_back(min(nums[0],nums[1]));
    for (int i = 2;i < nums.size();i++) {
        heap_insert(max_heap,min_heap,nums[i]);
        result.push_back(media(max_heap,min_heap));
    }
    return result;
}

int main() {
    int a[5] = {1,2,3,4,5};
    vector<int> test(a,a+5);
    vector<int> result = medianII(test);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    return 0;
}
