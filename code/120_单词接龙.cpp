#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <queue>
//#include <unordered_set>

using namespace std;

struct record {
    string data;
    int length;
};

int ladderLength(string &start, string &end, unordered_set<string> &dict) {
    if (start == "" || end == "") return 0;
    if (start == end) return 1;
    queue<record> record_queue;
    struct record s;
    s.data = start;
    s.length = 1;
    record_queue.push(s);
    dict.erase(start);
    while (!record_queue.empty()) {
        record temp = record_queue.front();
        record_queue.pop();
        for (int i = 0;i < temp.data.length();i++) {
            string str = temp.data;
            for (char j = 'a';j <= 'z';j++) {
                if (str[i] == j) continue;
                if (str == end) return temp.length + 1;
                str[i] = j;
                if (dict.find(str) != dict.end()) {
                    struct record r;
                    r.data = str;
                    r.length = temp.length + 1;
                    record_queue.push(r);
                    dict.erase(str);
                }
            }
        }
    }
    return 0;
}

int main() {
    string a = "mart";
    string b = "karma";
    //cout << minDistance(a,b) << endl;
    return 0;
}

