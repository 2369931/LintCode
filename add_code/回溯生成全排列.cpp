#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//next_permutation
//prev_permutation

void generate (vector<vector<int> > &result, vector<int> &temp, int index, int n) {
    if (index == n){
        result.push_back(temp);
    }
    else {
        for (int i = 0;i < n;i++) {
            vector<int>::iterator it = find(temp.begin(),temp.end(),i+1);
            if (it == temp.end()) {
                temp.push_back(i+1);
                generate(result,temp,index+1,n);
                temp.pop_back();
            }
        }
    }
}

int main() {
    vector<vector<int> > result;
    vector<int> temp;
    generate(result,temp,0,10);
    for (int i = 0;i < result.size();i++) {
        for (int j = 0;j < result[i].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
