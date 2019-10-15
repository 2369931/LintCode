#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>

using namespace std;

vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<int> res;
    int n = prerequisites.size();
    if (n == 0) {
        for (int i = 0;i < numCourses;i++) {
            res.push_back(i);
        }
        return res;
    }
    for (int i = 0;i < prerequisites.size();i++) {
        int temp = prerequisites[i].first;
        prerequisites[i].first = prerequisites[i].second;
        prerequisites[i].second = temp;
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
        return res;
    }
    int count = 0;
    while (!q.empty()) {
        int index = q.front();
        q.pop();
        count ++;
        res.push_back(index);
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
    /*for (auto c : indegree) {
        if (c.second != 0) {
            return false;
        }
    }
    return true;*/
    if (count < numCourses) {
        vector<int> temp;
        return temp;
    }
    else {
        return res;
    }
}

int main() {
    return 0;
}




vector<int> findOrder_2(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<int> r; r.reserve(numCourses);
    vector<int> indegrees(numCourses, 0);
    vector<vector<int>> childs; childs.resize(numCourses);
    for(int i = 0; i < prerequisites.size(); ++i) {
        pair<int, int>& t = prerequisites[i];
        ++indegrees[t.first];
        childs[t.second].push_back(t.first);
    }
    vector<int>* buf = new vector<int>();
    vector<int>* buf2 = new vector<int>();
    for(int i = 0; i < numCourses; ++i) {
        if(indegrees[i] == 0) {
            r.push_back(i);
            buf->push_back(i);
        }
    }
    while(buf->size()) {
        buf2->clear();
        for(int i = 0; i < buf->size(); ++i) {
            vector<int>& arr = childs[(*buf)[i]];
            for(int j = 0; j < arr.size(); ++j) {
                if(--indegrees[arr[j]] == 0) {
                    r.push_back(arr[j]);
                    buf2->push_back(arr[j]);
                }
            }
        }
        vector<int>* tmp = buf;
        buf = buf2;
        buf2 = tmp;
    }
    if(r.size() < numCourses) return vector<int>();
    return r;
}
