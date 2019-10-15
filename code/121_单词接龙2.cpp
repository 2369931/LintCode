class Solution {
public:
    /**
    * @param start, a string
    * @param end, a string
    * @param dict, a set of string
    * @return a list of lists of string
    */
    struct Destination {
        int num = 0;
        vector<string> str;
    };
    struct Node {
        unordered_set<string> last;
    };
    map<string, Node> node;
    map<string, bool> isPassed;
    vector<vector<string>> result;
    void DFS(vector<string> path,string str,int count,const string& start,const int& max) {
        path.push_back(str);
        if (str == start) {
            result.push_back(path);
            reverse(result.back().begin(), result.back().end());
        }
        if (count == max) return;
        for (auto i : node[str].last) {
            DFS(path, i, count + 1, start, max);
        }
        return;
    }
    void BFS(queue<string> &order, map<string, Destination> m, const string start,const string end) {
        int max=1;
        while (!order.empty() && !node[end].last.size()) {
            int num = order.size();
            max++;
            for (int i = 0; i < num; i++) {
                string s = order.front();
                isPassed[s] = true;
                order.pop();
                if (m[s].num != 0) {
                    for (auto i : m[s].str) {
                        if (!isPassed[i]) {
                            if (node[i].last.size() == 0) {
                                order.push(i);
                            }
                            node[i].last.insert(s);
                        }
                    }
                }
            }
        }
        vector<string> path;
        DFS(path, end, 1, start, max);
        return;
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        dict.insert(start);
        dict.insert(end);
        map<string, Destination> m;
        for (auto i : dict) {
            for (int j = 0; j<i.size(); j++) {
                for (int k = 0; k<26; k++) {
                    string tmp = i;
                    tmp[j] = 'a' + k;
                    if (dict.find(tmp)!=dict.end() && strcmp(tmp.c_str(), i.c_str())) {
                        m[i].num++;
                        m[i].str.push_back(tmp);
                    }
                }
            }
        }
        queue<string> order;
        order.push(start);
        BFS(order, m, start,end);

        return result;
    }
};
