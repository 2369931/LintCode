#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>

using namespace std;

int strToint (string str) {
    stringstream ss;
    ss << str;
    int temp = 0;
    ss >> temp;
    return temp;
}

int partition_vec(vector<int>& visited, int index, int n, string &str) {
    if (index == str.length()) {
        vector<int> res;
        for (int i = 1;i < visited.size();i++) {
            if (visited[i] == 0) {
                res.push_back(i);
            }
        }
        if (res.size() == 1) {
            return res[0];
        }
        else {
            return -1;
        }
    }
    if (str[index] == '0') {
        return -1;
    }
    for (int i = 1;i < 3;i++) {
        int temp = strToint(str.substr(index,i));
        if (temp >= 1 && temp <= n && visited[temp] == 0) {
            visited[temp] = 1;
            int val = partition_vec(visited,index+i,n,str);
            if (val != -1) {
                return val;
            }
            visited[temp] = 0;
        }
    }
    return -1;
}

int findMissing2(int n, string &str) {
    vector<int> visited(n+1,0);
    return partition_vec(visited,0,n, str);
}

int main() {
    string str = "19201234567891011121314151618";
    cout << findMissing2(20,str) << endl;
    return 0;
}

