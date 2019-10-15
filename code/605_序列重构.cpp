#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>

using namespace std;

bool sequenceReconstruction(vector<int> &org, vector<vector<int> > &seqs) {
    map<int,set<int> > neighborMap;
    map<int,int> indegreeMap;
    queue<int> q;
    if (org.empty()) {
        if (seqs.empty()) return true;
        if (seqs.size() == 1 && seqs[0].empty()) return true;
    }
    if (org.empty() || seqs.empty() || seqs[0].empty()) {
        return false;
    }
    for (auto v : seqs) {
        for (int i = 0;i < v.size()-1;i++) {
            if (neighborMap[v[i]].find(v[i+1]) == neighborMap[v[i]].end()) {
                neighborMap[v[i]].insert(v[i+1]);
                if (indegreeMap.find(v[i+1]) != indegreeMap.end()) {
                    indegreeMap[v[i+1]] ++;
                }
                else {
                    indegreeMap[v[i+1]] = 1;
                }
            }
        }
    }
    for (int i = 0;i <= org.size();i++) {
        if (indegreeMap[i] == 0) {
            q.push(i);
        }
    }
    int index = 0;

    while (q.size() == 1) {
        int n = q.front();
        q.pop();
        if (n != org[index]) {
            return false;
        }
        index ++;
        for (auto i : neighborMap[n]) {
            indegreeMap[i] --;
            if (indegreeMap[i] == 0) {
                q.push(i);
            }
        }
    }
    return index == org.size();
}

int main() {
    return 0;
}
