#include <iostream>
#include <queue>
#include <string>
#include <sstream>

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

string serialize(TreeNode * root) {
    queue<TreeNode*> tq;
    string result = "";
    int num = 0;
    if (root == NULL) {
        return "#";
    }
    tq.push(root);
    while(!tq.empty()) {
        TreeNode* temp = tq.front();
        tq.pop();
        if (temp != NULL) {
            stringstream stream;
            stream << temp->val;
            string string_temp = stream.str();
            result += string_temp;
            result += ",";
            tq.push(temp->left);
            tq.push(temp->right);
        }
        else {
            result += "#,";
        }
    }
    for (int i = result.length()-1;i >= 0;i --) {
        if (result[i] != ',' &&result[i] != '#') {
            num = i;
            break;
        }
    }
    string new_result = "";
    for (int i = 0;i <= num;i ++) {
        new_result += result[i];
    }
    return new_result;
}

string split(string s, int i,int j) {
    string result = "";
    for (int k = i;k < j;k ++) {
        result += s[k];
    }
    return result;
}

TreeNode * deserialize(string & data) {
    if (data == "#")
        return NULL;
    data += ",";
    vector<string> new_data;
    queue<TreeNode*> tq;
    int i = 0;
    while(i < data.length()) {
        int start = i;
        while (data[i] != ',') {
            i ++;
        }
        new_data.push_back(split(data,start,i));
        i++;
    }
    stringstream stream(new_data[0]);
    int val = 0;
    stream >> val;
    TreeNode* root = new TreeNode(val);
    tq.push(root);
    i = 1;
    while (i < new_data.size()) {
        TreeNode * root_now = tq.front();
        tq.pop();
        if (new_data[i] != "#") {
            stringstream stream_left(new_data[i]);
            stream_left >> val;
            TreeNode * left = new TreeNode(val);
            root_now->left = left;
            tq.push(left);
        }
        else {
            root_now->left = NULL;
        }
        i ++;
        if (i < new_data.size()) {
            if (new_data[i] != "#") {
                stringstream stream_right(new_data[i]);
                stream_right >> val;
                TreeNode * right = new TreeNode(val);
                root_now->right = right;
                tq.push(right);
            }
            else {
                root_now->right = NULL;
            }
            i ++;
        }
    }
    return root;
}

int main() {
    TreeNode* root = new TreeNode(3);
    TreeNode left(9);// = new TreeNode(9);
    root->left = &left;
    TreeNode right(20);// = new TreeNode(20);
    root->right = &right;
    TreeNode left1(15);// = new TreeNode(15);
    TreeNode right1(7);// = new TreeNode(7);
    root->right->left = &left1;
    root->right->right = &right1;
    cout << serialize(root) << endl;
    string test = "3,9,20,#,#,15,7";
    deserialize(test);
    return 0;
}
