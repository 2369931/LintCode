#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class SegmentTreeNode {
public:
    int start, end;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end) {
        this->start = start, this->end = end;
        this->left = this->right = NULL;
    }
}

SegmentTreeNode * build(int start, int end) {
    if (start > end) {
        return NULL;
    }
    SegmentTreeNode * root = new SegmentTreeNode(start, end);
    if (start < end) {
        int mid = (start + end) / 2;
        root->left = build(start, mid);
        root->right = build(mid + 1, end);
    }
    return root;
}


