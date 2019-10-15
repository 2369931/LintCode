#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>

using namespace std;

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
    int n = prerequisites.size();
    if (n == 0) {
        return true;
    }
    map<int, set<int> > record;
    map<int, int> indegree;
    for (int i = 0;i < numCourses;i++) {
        indegree[i] = 0;
    }
    for (int i = 0;i < n;i++) {
        if (prerequisites[i].first >= numCourses || prerequisites[i].second >= numCourses) {
            continue;
        }
        map<int,set<int> >::iterator it_record = record.find(prerequisites[i].first);
        if (it_record == record.end()) {
            set<int> temp;
            temp.insert(prerequisites[i].second);
            record[prerequisites[i].first] = temp;
            indegree[prerequisites[i].second] += 1;
        }
        else {
            set<int>::iterator it_set = record[prerequisites[i].first].find(prerequisites[i].second);
            if (it_set == record[prerequisites[i].first].end()) {
                record[prerequisites[i].first].insert(prerequisites[i].second);
                indegree[prerequisites[i].second] += 1;
            }
        }

    }
    queue<int> q;
    for (auto c : indegree) {
        if (c.second == 0) {
            q.push(c.first);
        }
    }
    if (q.size() == 0) {
        return false;
    }
    int count = 0;
    while (!q.empty()) {
        int index = q.front();
        q.pop();
        count ++;
        map<int,set<int> >::iterator it_record = record.find(index);
        if (it_record != record.end()) {
            for (auto c : it_record->second) {
                indegree[c] --;
                if (indegree[c] == 0) {
                    q.push(c);
                }
            }
        }
    }
    for (auto c : indegree) {
        if (c.second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    return 0;
}
