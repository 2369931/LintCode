#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
    if (node == NULL) return node;
    UndirectedGraphNode * new_node = new UndirectedGraphNode(node->label);
    map<UndirectedGraphNode *, UndirectedGraphNode *> match;
    map<UndirectedGraphNode *, bool> isExist;
    queue<UndirectedGraphNode *> q;
    q.push(node);
    match[node] = new_node;
    isExist[node] = true;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        for (int i = 0;i < node->neighbors.size(); i++) {
            if (isExist[node->neighbors[i]] == false) {
                UndirectedGraphNode * temp_node = new UndirectedGraphNode(node->neighbors[i]->label);
                isExist[node->neighbors[i]] = true;
                match[node->neighbors[i]] = temp_node;
                q.push(node->neighbors[i]);
                match[node]->neighbors.push_back(temp_node);
            }
            else {
                match[node]->neighbors.push_back(match[node->neighbors[i]]);
            }
        }
    }
    return new_node;
}

int main() {
}
