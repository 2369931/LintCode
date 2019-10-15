#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<string> &res, string temp, int target, int cur_val, int pre_val, int pos, string num) {
    if (pos == num.size() && cur_val == target) {
        res.push_back(temp);
        return;
    }
    for (int i = pos+1;i <= num.size();i++) {
        string tmp = num.substr(pos,i-pos);
        long long n = stoll(tmp);
        if (tmp[0] == '0' && tmp.size() > 1) {
            break;
        }
        else {
            if (pos == 0) {
                dfs(res,tmp,target,n,n,i,num);
            }
            else {
                dfs(res,temp + "+" + tmp,target,cur_val+n,n,i,num);
                dfs(res,temp + "-" + tmp,target,cur_val-n,-n,i,num);
                dfs(res,temp + "*" + tmp,target,cur_val - pre_val + pre_val*n,pre_val*n,i,num);
            }
        }
    }
}

vector<string> addOperators(string &num, int target) {
    vector<string> res;
    int n = num.length();
    if (n == 0) {
        return res;
    }
    string temp = "";
    dfs(res,temp,target,0,0,0,num);
    return res;
}

int main() {
    return 0;
}
