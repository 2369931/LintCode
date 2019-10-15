#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int value) {
        this->val = value;
        this->left = NULL;
        this->right = NULL;
    }
};

void pre_order_1(TreeNode * root) {
    if (root != NULL) {
        cout << root->val << " ";
        pre_order_1(root->left);
        pre_order_1(root->right);
    }
}

void pre_order_2(TreeNode * root) {
    stack<TreeNode*> s;
    TreeNode * temp = root;
    while (temp != NULL || !s.empty()) {
        if (temp != NULL) {
            cout << temp->val << " ";
            s.push(temp);
            temp = temp->left;
        }
        else {
            TreeNode * node = s.top();
            s.pop();
            temp = node->right;
        }
    }
}

void mid_order_1(TreeNode * root) {
    if (root != NULL) {
        mid_order_1(root->left);
        cout << root->val << " ";
        mid_order_1(root->right);
    }
}

void mid_order_2(TreeNode * root) {
    stack<TreeNode*> s;
    TreeNode * temp = root;
    while (temp != NULL || !s.empty()) {
        if (temp != NULL) {
            s.push(temp);
            temp = temp->left;
        }
        else {
            TreeNode * node = s.top();
            s.pop();
            cout << node->val << " ";
            temp = node->right;
        }
    }
}

void post_order_1(TreeNode * root) {
    if (root != NULL) {
        post_order_1(root->left);
        post_order_1(root->right);
        cout << root->val << " ";
    }
}

void post_order_2(TreeNode * root) {
    stack<TreeNode*> s;
    TreeNode * pre = root;
    s.push(root);
    while (!s.empty()) {
        TreeNode * cur = s.top();
        if ((cur->left == NULL && cur->right == NULL) ||
        (pre == cur->left || pre == cur->right)) {
            s.pop();
            cout << cur->val << " ";
            pre = cur;
        }
        else {
            if (cur->right) {
                s.push(cur->right);
            }
            if (cur->left) {
                s.push(cur->left);
            }
        }
    }
}

void level_order(TreeNode * root) {
    if (root != NULL) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode * node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
}

int main() {
    TreeNode * root = new TreeNode(1);
    TreeNode * a = new TreeNode(2);
    TreeNode * b = new TreeNode(3);
    TreeNode * c = new TreeNode(4);
    TreeNode * d = new TreeNode(5);
    TreeNode * e = new TreeNode(6);
    TreeNode * f = new TreeNode(7);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    b->right = f;
    pre_order_1(root);
    cout << endl;
    pre_order_2(root);
    cout << endl;
    mid_order_1(root);
    cout << endl;
    mid_order_2(root);
    cout << endl;
    post_order_1(root);
    cout << endl;
    post_order_2(root);
    cout << endl;
    level_order(root);
    cout << endl;
    delete root;
    root = NULL;
    delete a;
    a = NULL;
    delete b;
    b = NULL;
    delete c;
    c = NULL;
    delete d;
    d = NULL;
    delete e;
    e = NULL;
    delete f;
    f = NULL;
    return 0;
}
