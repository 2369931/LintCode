#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t) {
    queue<DirectedGraphNode*> q;
    map<DirectedGraphNode*, bool> visited;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        DirectedGraphNode * temp = q.front();
        q.pop();
        if (temp == t) return true;
        for (int i = 0;i < temp->neighbors.size();i++) {
            if (visited[temp->neighbors[i]] != true) {
                q.push(temp->neighbors[i]);
                visited[temp->neighbors[i]] = true;
            }
        }
    }
    return false;
}

int main() {
}

