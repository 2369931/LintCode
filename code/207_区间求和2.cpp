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

class Solution {
class SegmentTreeNode{
 public:
      int start, end;
      long long max;
      SegmentTreeNode *left, *right;
      SegmentTreeNode(int start, int end, int max) {
          this->start = start;
          this->end = end;
          this->max = max;
          this->left = this->right = NULL;
      }
 };
public:
    SegmentTreeNode * root;

    Solution(vector<int> A) {
        this->root = build(0,A.size()-1,A);
    }

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

    long long query_t(SegmentTreeNode * root, int start, int end) {
        if (root == NULL || start > end) return 0;
        int mid = (root->start + root->end) / 2;
        if (start <= root->start && end >= root->end) {
            return root->max;
        }
        else if (mid < start) {
            return query_t(root->right, start, end);
        }
        else if (mid + 1 > end) {
            return query_t(root->left, start, end);
        }
        else {
            return query_t(root->left, start, mid) + query_t(root->right, mid + 1, end);
        }
    }

    long long query(int start, int end) {
        return query_t(root, start, end);
    }

    void modify_t(SegmentTreeNode * root, int index, int value) {
        if (root == NULL || index < root -> start || index > root -> end) return;
        if (root->start == index && root->end == index) {
            root->max = value;
            return;
        }
        else {
            int mid = (root->start + root->end)/2;
            if (index > mid) {
                modify_t(root->right,index,value);
            }
            else {
                modify_t(root->left,index,value);
            }
        }
        root->max = root->left->max + root->right->max;
        return;
    }

    void modify(int index, int value) {
        modify_t(root, index, value);
    }
};

