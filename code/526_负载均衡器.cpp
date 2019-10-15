#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class LoadBalancer {
public:
    vector<int> servers;
    LoadBalancer() {
        // do intialization if necessary
    }

    void add(int server_id) {
        vector<int>::iterator it = find(servers.begin(),servers.end(),server_id);
        if (it == servers.end())
            servers.push_back(server_id);
    }

    void remove(int server_id) {
        for (vector<int>::iterator it = servers.begin();it != servers.end();) {
            if (*it == server_id) {
                it = servers.erase(it);
            }
            else {
                it ++;
            }
        }
    }

    int pick() {
        int n = servers.size();
        if (n != 0) {
            srand((int)time(0));
            return servers[rand()%n];
        }
    }
};

int main() {
    LoadBalancer L;
    L.add(1);
    L.add(1);
    L.add(6);
    L.add(3);
    L.add(4);
    L.add(5);
    cout << L.pick() << endl;
    cout << L.pick() << endl;
    return 0;
}
