#include <iostream>
#include <vector>
#include <map>

using namespace std;

class ConnectingGraph3 {
public:
    int node_number;
    vector<int> node_record;
    int cnt;
    ConnectingGraph3(int number) {
        node_number = number;
        for (int i = 0;i < number;i++) {
            node_record.push_back(i);
        }
        cnt = number;
    }

    int unionSearch(int target, vector<int>& node_record) {
        while (target != node_record[target]) {
            node_record[target] = node_record[node_record[target]];
            target = node_record[target];
        }
        return target;
    }

    void connect(int a, int b) {
        int root1 = unionSearch(a,node_record);
        int root2 = unionSearch(b,node_record);
        if (root1 != root2) {
            node_record[root1] = root2;
            cnt --;
        }
    }

    int query() {
        return cnt;
    }
};

int main() {
    ConnectingGraph3 g(6);
    cout << g.query() << endl;
    g.connect(5,6);
    cout << g.query() << endl;
    g.connect(1,4);
    cout << g.query() << endl;
    g.connect(4,6);
    cout << g.query() << endl;
    return 0;
}
