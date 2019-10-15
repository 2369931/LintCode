#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

bool judge(vector<vector<int> > &record, int n, int target) {
    int in_number = 0;
    for (int i = 0;i < n;i ++) {
        if (record[target][i] != 0) {
            return false;
        }
        in_number += record[i][target];
    }
    if (in_number == n-1) {
        return true;
    }
    else {
        return false;
    }
}

int findCelebrity(int n) {
    if (n == 0) {
        return -1;
    }
    else if (n == 1) {
        return 0;
    }
    else {
        vector<vector<int> > record(n, vector<int>(n,0));
        for (int i = 0;i < n;i ++) {
            for (int j = 0;j < n;j++) {
                if (i != j)
                    record[i][j] = knows(i,j);
            }
        }
        for (int i = 0;i < n;i++) {
            if (judge(record,n,i)) {
                return i;
            }
        }
        return -1;
    }
}
