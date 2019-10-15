#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void create(vector<vector<int> > &result, vector<int> &temp, int cur, int n ,int k) {
    if (temp.size() == k) {
        result.push_back(temp);
        return;
    }
    for (int i = cur;i <= n;i++) {
        temp.push_back(i);
        create(result,temp,i+1,n,k);
        temp.pop_back();
    }
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;
    if (n == 0 || k == 0) return result;
    vector<int> temp;
    create(result,temp,1,n,k);
    return result;
}

int main() {
    vector<vector<int> > result = combine(4, 2);
    for (int i = 0;i < result.size();i++) {
        for (int j = 0;j < result[i].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
