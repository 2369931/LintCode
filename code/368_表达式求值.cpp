#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

class ExpressionTreeNode {
public:
    string symbol;
    ExpressionTreeNode *left, *right;
    ExpressionTreeNode(string symbol) {
    this->symbol = symbol;
    this->left = this->right = NULL;
    }
};

int str_to_int(string s) {
    stringstream ss;
    ss << s;
    int result = 0;
    ss >> result;
    ss.clear();
    return result;
}

string int_to_str(int a) {
    stringstream ss;
    ss << a;
    string result = "";
    ss >> result;
    ss.clear();
    return result;
}

ExpressionTreeNode * build(vector<string> &expression) {
   // write your code here

    vector<string> sbegin = beginE(expression);
    stack<ExpressionTreeNode *> res;
    //相当于把前缀表达式的计算，换成了建立节点而已
    for(auto x : sbegin )
    {
        if(cmp(x) == 0)
        {
            ExpressionTreeNode *temp = new ExpressionTreeNode(x);
            res.push(temp);
        }
        else
        {
            //不是数字，先弹出两个，再压入堆栈
            ExpressionTreeNode *temp = new ExpressionTreeNode(x);
            temp -> left = res.top();
            res.pop();
            temp -> right = res.top();
            res.pop();
            res.push(temp);
        }

    }

    return res.empty() ? NULL:res.top();


}

vector<string> beginE(vector<string> &stemp)
{
    vector<string> sbegin;
    stack<string> s;
    int n = stemp.size();
    for(int i = n-1; i>=0; i--)
    {
        if(cmp(stemp[i]) == 0)
            sbegin.push_back(stemp[i]);
        else if(stemp[i] == "(")
        {
            while(s.top() != ")")
            {
                sbegin.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(true)
            {
                if(s.empty() || stemp[i] == ")" || s.top() == ")" || (cmp(stemp[i]) >= cmp(s.top())) )
                {
                    s.push(stemp[i]);
                    break;
                }
                else
                {
                    sbegin.push_back(s.top());
                    s.pop();
                }
            }
        }
    }
    while(!s.empty())
    {
        sbegin.push_back(s.top());
        s.pop();
    }
    return sbegin;
}

int cmp(string a)
{
    switch (a[0]){
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '(':
            return 3;
        case ')':
            return 3;
        default:
            return 0;
    }
}

int cmp_t(string a)
{
    switch (a[0]){
        case '+':
            return 1;
        case '-':
            return 2;
        case '*':
            return 3;
        case '/':
            return 4;
        default:
            return 0;
    }
}

void calculate(ExpressionTreeNode * root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) return;
    if (root->left != NULL)
        calculate(root->left);
    if (root->right != NULL)
        calculate(root->right);
    if (cmp(root->left->symbol) == 0 && cmp(root->right->symbol) == 0) {
        int a = str_to_int(root->left->symbol);
        int b = str_to_int(root->right->symbol);
        int c = cmp_t(root->symbol);
        int temp = 0;
        if (c == 1) {
            temp = a + b;
        }
        if (c == 2) {
            temp = a - b;
        }
        if (c == 3) {
            temp = a * b;
        }
        if (c == 4) {
            temp = a / b;
        }
        if (c != 0) {
          root->symbol = int_to_str(temp);
        }
    }
}

int evaluateExpression(vector<string> &expression) {
    if (expression.size() == 0) return 0;
    int flag = 0;
    for (int i = 0;i < expression.size();i++) {
        if (cmp(expression[i]) == 0) {
                flag = 1;
                break;
            }
        }
    if (flag == 0) return 0;
    ExpressionTreeNode * root = build(expression);
    if (expression.size() != 1) {
        calculate(root);
    }
    return str_to_int(root->symbol);
}


