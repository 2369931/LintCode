#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class SegmentTreeNode {
public:
    int start;
    int end;
    long long max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, long long max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};

SegmentTreeNode * build(int start, int end, vector<int>&num) {
    if (start > end) {
        return NULL;
    }
    SegmentTreeNode * root = new SegmentTreeNode(start, end, 0);
    if (start < end) {
        int mid = (start + end) / 2;
        root->left = build(start, mid, num);
        root->right = build(mid + 1, end, num);
        root->max = root->left->max + root->right->max;
    }
    else {
        root->max = num[start];
    }
    return root;
}

long long query(SegmentTreeNode * root, int start, int end) {
    if (root == NULL || start > end) return 0;
    int mid = (root->start + root->end) / 2;
    if (start <= root->start && end >= root->end) {
        return root->max;
    }
    else if (mid < start) {
        return query(root->right, start, end);
    }
    else if (mid + 1 > end) {
        return query(root->left, start, end);
    }
    else {
        return query(root->left, start, mid) + query(root->right, mid + 1, end);
    }
}

vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
    vector<long long> result;
    int n = A.size();
    if (n == 0) return result;
    SegmentTreeNode * root = build(0,n-1,A);
    for (int i = 0;i < queries.size();i++) {
        result.push_back(query(root,queries[i].start,queries[i].end));
    }
    return result;
}

int main() {
}


