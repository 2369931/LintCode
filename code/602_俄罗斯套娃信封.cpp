#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    int n = envelopes.size();
    if (n == 0) {
        return 0;
    }
    vector<int> dp(n,1);
    sort(envelopes.begin(), envelopes.end());
    int res = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < i;j++) {
            if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                dp[i] = max(dp[i],dp[j]+1);
        }
        res = max(res, dp[i]);
    }
    return res;
}

///¶þ·Ö·¨
static bool cmp(pair<int,int> &a,pair<int,int>& b){
    if(a.first==b.first) return a.second>b.second;
    else return a.first<b.first;
}
int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    int n=envelopes.size(),len=0;
    sort(envelopes.begin(),envelopes.end(),cmp);
    vector<int> vec(n,0);
    for(int i=0;i<n;i++){
        int m=envelopes[i].second;
        auto it=lower_bound(vec.begin(),vec.begin()+len,m);
        if(it==vec.begin()+len) vec[len++]=m;
        else *it=m;
    }
    return len;
}

