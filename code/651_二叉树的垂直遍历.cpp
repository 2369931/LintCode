#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

void level_order(TreeNode * root, map<int,vector<int> > &record, vector<int> &index, int pre_value) {
    if (root != NULL) {
        queue<TreeNode*> q;
        queue<int> int_q;
        q.push(root);
        int_q.push(pre_value);
        index.push_back(pre_value);
        record[pre_value].push_back(root->val);
        while (!q.empty()) {
            TreeNode * temp = q.front();
            q.pop();
            int v = int_q.front();
            int_q.pop();
            if (temp->left) {
                q.push(temp->left);
                int_q.push(v-1);
                vector<int>::iterator it = find(index.begin(),index.end(),v-1);
                if (it == index.end())
                    index.push_back(v-1);
                record[v-1].push_back(temp->left->val);
            }
            if (temp->right) {
                q.push(temp->right);
                int_q.push(v+1);
                vector<int>::iterator it = find(index.begin(),index.end(),v+1);
                if (it == index.end())
                    index.push_back(v+1);
                record[v+1].push_back(temp->right->val);
            }
        }
    }
}

vector<vector<int> > verticalOrder(TreeNode * root) {
    vector<vector<int> > result;
    if (root == NULL) {
        return result;
    }
    map<int,vector<int> > record;
    vector<int> index;
    level_order(root,record,index,0);
    sort(index.begin(),index.end());
    for (int i = 0;i < index.size();i++) {
        result.push_back(record[index[i]]);
    }
    return result;
}

int main() {
    TreeNode * root = new TreeNode(3);
    TreeNode * a = new TreeNode(9);
    TreeNode * b = new TreeNode(20);
    TreeNode * c = new TreeNode(15);
    TreeNode * d = new TreeNode(7);
    root->left = a;
    root->right = b;
    b->left = c;
    b->right = d;
    //map<int,vector<int> > record;
    //vector<int> index;
    //level_order(root,record,index,0);
    vector<vector<int> > result = verticalOrder(root);
    for (int i = 0;i < result.size();i++) {
        for (int j = 0;j < result[i].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

