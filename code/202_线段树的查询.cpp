#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

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
}

int query(SegmentTreeNode * root, int start, int end) {
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
        return max(query(root->left, start, mid), query(root->right, mid + 1, end));
    }
}



