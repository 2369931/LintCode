#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
    vector<DirectedGraphNode*> result;
    int n = graph.size();
    if (n == 0) {
        return result;
    }
    map<DirectedGraphNode*,int> record;
    queue<DirectedGraphNode*> q;
    for (int i = 0;i < graph.size();i++) {
        record[graph[i]] = 0;
    }
    for (int i = 0;i < graph.size();i++) {
        for (int j = 0;j < graph[i]->neighbors.size();j++) {
            record[graph[i]->neighbors[j]] += 1;
        }
    }
    map<DirectedGraphNode*,int>::iterator iter;
    for(iter = record.begin(); iter != record.end(); iter++) {
        if (iter->second == 0) {
            q.push(iter->first);
        }
    }
    while (!q.empty()) {
        DirectedGraphNode* cur = q.front();
        result.push_back(cur);
        q.pop();
        for (int i = 0;i < cur->neighbors.size();i++) {
            record[cur->neighbors[i]] -= 1;
            if (record[cur->neighbors[i]] == 0) {
                q.push(cur->neighbors[i]);
            }
        }
    }
    return result;
}
