#include <iostream>
#include <vector>

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

bool validTree(int n, vector<vector<int> > &edges) {
    if (edges.size() == 0 && n == 1) return true;
    if (edges.size() == 0 && n > 1) return false;
    vector<int> degree(n,0);
    vector<int> record(n,0);
    int graph[n][n];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0;i < edges.size();i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
        degree[edges[i][0]] ++;
        degree[edges[i][1]] ++;
    }
    for (int i = 0;i < n;i++) {
        if (degree[i] == 0) return false;
    }
    int s = 0;
    while (s < n) {
        int flag = 0;
        for (int i = 0;i < n;i++) {
            if (degree[i] <= 1 && record[i] == 0) {
                for (int j = 0;j < n;j++) {
                    if (graph[i][j] == 1) {
                        degree[j] --;
                    }
                }
                s ++;
                record[i] = 1;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int> > vec;
    int a[2] = {0,1};
    vector<int> v_a(a,a+2);
    int b[2] = {0,2};
    vector<int> v_b(b,b+2);
    int c[2] = {0,3};
    vector<int> v_c(c,c+2);
    int d[2] = {3,0};
    vector<int> v_d(d,d+2);
    vec.push_back(v_a);
    vec.push_back(v_b);
    vec.push_back(v_c);
    vec.push_back(v_d);
    //validTree(5, vec);
    cout << validTree(5, vec) << endl;
    return 0;
}


