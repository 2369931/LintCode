#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class ParentTreeNode {
public:
    int val;
    ParentTreeNode *parent, *left, *right;
}

ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
    if (root == NULL) {
        return NULL;
    }
    if (A == root || B == root) return root;
    int length_a = 0;
    int length_b = 0;
    ParentTreeNode * a = A;
    ParentTreeNode * b = B;
    while (a != root) {
        a = a->parent;
        length_a ++;
    }
    while (b != root) {
        b = b->parent;
        length_b ++;
    }
    int temp = 0;
    if (length_b > length_a) {
        a = B;
        b = A;
        temp = length_b - length_a;
    }
    else {
        a = A;
        b = B;
        temp = length_a - length_b;
    }
    while (temp > 0) {
        a = a->parent;
        temp --;
    }
    while (true) {
        if (a == b) {
            return a;
        }
        a = a->parent;
        b = b->parent;
    }
}
