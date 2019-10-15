#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class SegmentTreeNode {
public:
    int start, end, count;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end) {
        this->start = start;
        this->end = end;
        this->left = this->right = NULL;
        this->count = 0;
    }
};

SegmentTreeNode * build(int start, int end) {
    if (start > end) return NULL;
    SegmentTreeNode * root = new SegmentTreeNode(start, end);
    if (start < end) {
        int mid = (start + end)/2;
        root->left = build(start, mid);
        root->right = build(mid+1,end);
    }
    return root;
}

int query(SegmentTreeNode * root, int start, int end) {
    if (root == NULL || start > end || root->start > end || root->end < start) return 0;
    if (root->start >= start && root->end <= end) return root->count;
    int mid = (root->start + root->end)/2;
    if (start > mid) {
        return query(root->right, start, end);
    }
    else {
        return query(root->left, start, end);
    }
    return query(root->left,start,mid) + query(root->right,mid,end);
}

int query(SegmentTreeNode * root, int start, int end) {
    if(root == NULL) {return 0;}
    if(start > end || root->start > end || root->end < start) { return 0; }
    if(start <= root->start && end >= root->end) {return root->count; }
    int mid = (root->start + root->end) >> 1;
    int leftCount = query(root->left, start, min(mid, end));
    int rightCount = query(root->right, max(mid, start), end);
    return leftCount + rightCount;
}

void modify(SegmentTreeNode * root, int index) {
    if (root == NULL) return;
    if (root->start == index && root->end == index) {
        root->count += 1;
        return;
    }
    int mid = (root->start + root->end)/2;
    if (index > mid) {
        modify(root->right, index);
    }
    else {
        modify(root->left, index);
    }
    if (root->right != NULL)
        root->count = root->left->count + root->right->count;
    else
        root->count = root->left->count;
}


vector<int> countOfSmallerNumberII(vector<int> &A) {
    vector<int> result;
    if (A.size() == 0) return result;
    SegmentTreeNode * root = build(0,10002);
    for (int i = 0;i < A.size();i++) {
        int temp = query(root,0,A[i]-1);
        result.push_back(temp);
        modify(root,A[i]);
    }
    return result;
}
