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
    SegmentTreeNode(int start, int end, int count) {
        this->start = start;
        this->end = end;
        this->count = count;
        this->left = this->right = NULL;
    }
}

int query(SegmentTreeNode * root, int start, int end) {
    if (root == NULL || start > end) return 0;
    int mid = (root->start + root->end) / 2;
    if (start <= root->start && end >= root->end) {
        return root->count;
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




