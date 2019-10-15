#include <iostream>

using namespace std;

class BSTreeNode {
public:
    int val;
    BSTreeNode * left;
    BSTreeNode * right;
    BSTreeNode (int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
    ~BSTreeNode () {
        delete left;
        delete right;
    }
};

class BSTree {
public:
    BSTreeNode * root;
    BSTree() {
        root = NULL;
    }
    ~BSTree() {
        delete root;
    }
    bool Insert(int data) {
        if (root == NULL) {
            root = new BSTreeNode(data);
            return true;
        }
        BSTreeNode * cur = root;
        BSTreeNode * parent = NULL;
        while (cur) {
            if (data < cur->val) {
                parent = cur;
                cur = cur->left;
            }
            else if (data > cur->val) {
                parent = cur;
                cur = cur->right;
            }
            else {
                return false;
            }
        }
        cur = new BSTreeNode(data);
        if (data < parent->val) {
            parent->left = cur;
        }
        else {
            parent->right = cur;
        }
        return true;
    }

    BSTreeNode * Find(int data) {
        BSTreeNode * cur = root;
        while (cur) {
            if (cur->val == data) {
                return cur;
            }
            else if (data < cur->val) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        return NULL;
    }

    bool Delete_1(int data) {
        return Delete(root,data);
    }

    bool Delete(BSTreeNode* root, int data) {
        /*BSTreeNode * cur = root;
        BSTreeNode * parent = NULL;
        while (cur) {
            if (cur->val == data) {
                break;
            }
            else if (data > cur->val) {
                parent = cur;
                cur = cur->right;
            }
            else {
                parent = cur;
                cur = cur->left;
            }
        }
        if (cur == NULL) {
            return false;
        }
        if (cur->right == NULL) {
            if (cur == root) {
                root = cur->left;
            }
            else {
                if (cur == parent->left) {
                    parent->left = cur->left;
                }
                else {
                    parent->right = cur->left;
                }
            }
        }
        else if (cur->left == NULL) {
            if (cur == root) {
                root = cur->right;
            }
            else {
                if (cur == parent->right) {
                    parent->right = cur->right;
                }
                else {
                    parent->left = cur->right;
                }
            }
        }
        else {
            BSTreeNode * del = cur->right;
            parent = cur;
            while (del->left) {
                parent = del;
                del = del->left;
            }
            cur->val = del->val; /// ????
            if (del == parent->left) {
                parent->left = del->right;
            }
            else {
                parent->right = del->right;
            }
            cur = del;
        }
        delete cur;
        return true;*/
        if (root == NULL) {
            return false;
        }
        else {
            if (data > root->val) {
                return Delete(root->right,data);
            }
            else if (data < root->val) {
                return Delete(root->left,data);
            }
            else {
                BSTreeNode del = *root;
                if (root->right == NULL) {
                    root = root->left;
                    delete del;
                    return true;
                }
                else if (root->left == NULL) {
                    root = root->right;
                    delete del;
                    return true;
                }
                else {
                    del = root->right;
                    while (del->left) {
                        del = del->left;
                    }
                    root->val = del->val;
                    return Delete(root->right,del->val);

                }
            }
        }
    }

    void print() {
        mid_order(root);
        cout << endl;
    }

    void mid_order(BSTreeNode * root) {
        if (root != NULL) {
            mid_order(root->left);
            cout << root->val << " ";
            mid_order(root->right);
        }
    }
};

int main() {
    int arr[10] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree bs;
	for (int i = 0; i < 10; i++)
		bs.Insert(arr[i]);
	bs.print();
	bs.Delete_1(7);
	bs.print();
    return 0;
}
