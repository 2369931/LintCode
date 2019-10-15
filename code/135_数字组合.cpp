#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<int> > &result, vector<int> &candidates, vector<int> &temp, int cur, int sum, int target) {
    if (sum == target) {
        result.push_back(temp);
        return;
    }
    else if(sum > target) {
        return;
    }
    for (int i = cur;i < candidates.size();i++) {
        sum += candidates[i];
        temp.push_back(candidates[i]);
        solve(result,candidates,temp,i,sum,target);
        sum -= temp[temp.size()-1];
        temp.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > result;
    vector<int> temp;
    int n = candidates.size();
    if (n == 0) return result;
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
    solve(result,candidates,temp,0,0,target);
    return result;
}

int main() {

}
