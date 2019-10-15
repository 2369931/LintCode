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
};


void modify(SegmentTreeNode * root, int index, int value) {
    if (index < root->start || index > root->end) return;
    if (root == NULL) return;
    if (root->start == root->end && root->start == index) {
        root->max = value;
        return;
    }
    int mid = (root->start+root->end)/2;
    if (mid >= index) {
        modify(root->left,index,value);
    }
    else {
        modify(root->right,index,value);
    }
    root->max = max(root->left->max, root->right->max);
}




