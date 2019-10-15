#include <iostream>
#include <vector>
#include <map>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int result = 0;
    int value = 0;
    int m = cost.size();
    for (int i = 0;i < gas.size();i++) {
        for (int j = i;j < i + m;j++) {
            if (j >= m) {
                value += gas[j%m];
                value -= cost[j%m];
            }
            else {
                value += gas[j];
                value -= cost[j];
            }
            if (value < 0) {
                break;
            }
        }
        if (value < 0) {
            value = 0;
        }
        else {
            return i;
        }
    }
    return -1;
}

int main() {
    int a[4] = {1,1,3,1};
    int b[4] = {2,2,1,1};
    vector<int> gas(a,a+4);
    vector<int> cost(b,b+4);
    cout << canCompleteCircuit(gas,cost) << endl;
    return 0;
}
