#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};

SegmentTreeNode * build_bottom_to_top(vector<int> &A, int start, int end) {
    if (start > end) {
        return NULL;
    }
    SegmentTreeNode * root = new SegmentTreeNode(start,end,0);
    if (start < end) {
        int mid = (start + end)/2;
        root->left = build_bottom_to_top(A,start,mid);
        root->right = build_bottom_to_top(A,mid+1,end);
        root->max = max(root->left->max,root->right->max);
    }
    else {
        root->max = A[start];
    }
    return root;
}

SegmentTreeNode * build(vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return NULL;
    }
    else {
        return build_bottom_to_top(A,0,n-1);
    }
}

