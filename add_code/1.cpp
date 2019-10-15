#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string intToString(int a) {
    stringstream ss;
    ss << a;
    string str = "";
    ss >> str;
    return str;
}

string charToString(char a) {
    stringstream ss;
    ss << a;
    string str = "";
    ss >> str;
    return str;
}

int count_number(vector<int> vec) {
    int res = 0;
    for (int i = 0;i < vec.size();i++) {
        if (vec[i] != 0) {
            res ++;
        }
    }
    return res;
}

void dpFind(vector<vector<int>> &graph, vector<bool> &record, int target, int & res) {
    if (!record[target]) {
        record[target] = true;
        int n = count_number(graph[target]);//.size() - 1;
        if (n == 0) {
            return;
        }
        res += n;
        for (int i = 0;i < n;i++) {
          dpFind(graph, record, graph[target][i],res);
        }
    }
    else {
        return;
    }
}

vector<string> costsOfNodes(vector<string> lines) {
    int n = lines.size();
    vector<string> res;
    vector<char> key;
    vector<vector<int>> graph(n, vector<int>(n,0));
    vector<bool> record(n,false);
    map<char, int> dict;
    if (n == 0) {
        return res;
    }
    for (int i = 0;i < n;i++) {
        record[i] = false;
        char str = lines[i][0];
        key.push_back(str);
        for (int j = 0;j < n;j++) {
           graph[i][j] = 0;
        }
    }
    sort(key.begin(), key.end());

    for (int i = 0;i < n;i++) {
        dict[key[i]] = i;
    }
    for (int i = 0;i < n;i++) {
        int y = dict[lines[i][0]];
        for (int j = 1;j < lines[i].length();j++) {
            int x = dict[lines[i][j]];
            graph[x][y] = 1;
        }
    }

    for (int i = 0;i < n;i ++) {
        int temp = 1;
        int target = dict[key[i]];
        for (int j = 0;j < n;j ++) {
            record[j] = false;
        }

        dpFind(graph, record, target, temp);
        //string strKey = key + "";
        string str = charToString(key[i]) + "," + intToString(temp);
        cout << key[i] << " " << intToString(temp) << endl;
        res.push_back(str);
    }
    return res;
}

int main() {
    vector<string> test;
    string a = "AENS";
    string b = "SHN";
    string c = "EN";
    string d = "H";
    string e = "N";
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);
    test.push_back(d);
    test.push_back(e);
    costsOfNodes(test);
    return 0;
}
