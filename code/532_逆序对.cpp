#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

long long res = 0;

long long reversePairs(vector<int> &A) {
    mergesort(A, 0 , A.size()-1);
    return res;
}

void mergesort(vector<int> &A, int start, int end) {
    int mid = (start + end)/2;
    if (start < end) {
        mergesort(A,start,mid);
        mergesort(A,mid+1,end);
        merge(A,start,mid,end);
    }
}

void merge(vector<int> &A, int start, int mid, int end) {
    vector<int> temp(end - start + 1);
    int i = start;
    int j = mid + 1;
    int t = 0;
    while (i <= mid && j <= end) {
        if (A[i] <= A[j]) {
            temp[t++] = A[i++];
        }
        else {
            res += mid - i + 1;
            temp[t++] = A[j++];
        }
    }
    while (i <= mid)
        temp[t++] = A[i++];
    while (j <= end)
        temp[t++] = A[j++];
    for (int i = 0;i < temp.size();i++) {
        A[i+start] = temp[i];
    }
}
