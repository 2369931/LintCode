#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int firstMissingPositive(vector<int> &A) {
    int n = A.size();
    if (n == 0) return 1;
    else if (n == 1) {
        if (A[0] < 0) return 1;
        else return A[0] + 1;
    }
    sort(A.begin(),A.end());
    for (int i = 0;i < A.size()-1;i++) {
        if (A[i] < 0 || A[i] == A[i+1]) continue;
        else if (A[i] != A[i+1] - 1) {
            return A[i] + 1;
        }
    }
    if (A[0] - 1 > 0) {
        return A[0] - 1;
    }
    else
        return A[n-1] + 1;
}

int firstMissingPositive(vector<int> A) {
    int n = A.size();
     for(int i=0;i<n;)
     {
         if(A[i]==i+1)
             i++;
         else
         {
             if(A[i]>=1&&A[i]<=n&& A[A[i]-1]!=A[i])
                 swap(A[i],A[A[i]-1]);
             else
                 i++;
         }
     }
    for(int i=0;i<n;i++)
        if(A[i]!=i+1)
            return i+1;
    return n+1;
}

int main() {
    int a[4] = {3,4,-1,1};
    vector<int> test(a,a+4);
    cout << firstMissingPositive(test) << endl;
    return 0;
}
