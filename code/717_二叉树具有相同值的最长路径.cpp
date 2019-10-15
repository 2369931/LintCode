#include <iostream>
#include <vector>

using namespace std;

int res = 0;
int N;
vector<vector<int>> adj;

void addEdge(int n, int m) {
    adj[n].push_back(m);
    adj[m].push_back(n);
}

int depth(vector<int> &A, vector<bool> &marked, int index) {
    int L = 0;
    int R = 0;
    marked[index] = true;
    bool flag = true;
    for (int j: adj[index]) {
        if (A[j] == A[index] && marked[j] == false) {
            if (flag) {
                L = depth(A, marked, j) + 1;
                flag = false;
            }
            else {
                R = depth(A, marked, j) + 1;
            }
        }
    }
    res = max(res,L+R);
    return max(L,R);
}

int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {
    int N = A.size();
    adj = vector<vector<int> >(N);
    for (int i = 0;i < N - 1;i++) {
        addEdge(E[i*2] - 1, E[i*2+1] - 1);
    }
    for (int i = 0;i < N;i++) {
        vector<bool> marked(N, false);
        depth(A, marked, i);
    }
    return res;
}
