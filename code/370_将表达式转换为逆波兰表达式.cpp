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

void calculate(ExpressionTreeNode * root, vector<string> &result) {
    if (root == NULL) return;
    if (root -> left != NULL) {
        calculate(root->left, result);
    }
    if (root -> right != NULL) {
        calculate(root->right, result);
    }
    result.push_back(root->symbol);
}

vector<string> convertToRPN(vector<string> &expression) {
    vector<string> result;
    if (expression.size() == 0) return result;
    ExpressionTreeNode * root = build(expression);
    calculate(root,result);
    return result;
}


