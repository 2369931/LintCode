#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

/*vector<int> find_min(vector<int> &A, int &record) {
    int n = A.size();
    if (n < 2) {
        return A;
    }
    vector<int> result;
    int min = INT_MAX;
    int index = 0;
    for (int i = 0;i < n-1;i++) {
        if (A[i] + A[i + 1] < min) {
            index = i;
            min = A[i] + A[i+1];
        }
    }
    record = min;
    for (int i = 0;i < n;i++) {
        if (i == index) {
            result.push_back(A[i] + A[i+1]);
            i++;
        }
        else {
            result.push_back(A[i]);
        }
    }
    return result;
}

int stoneGame(vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 0;
    }
    else if (n == 2) {
        return A[0] + A[1];
    }
    else {
        int result = 0;
        int temp = 0;
        vector<int> temp_vec = find_min(A,temp);
        result += temp;
        while(temp_vec.size() != 1) {
            temp_vec = find_min(temp_vec,temp);
            result += temp;
        }
        return result;
    }
}*/ //贪心只能局部最优

int weight(vector<int> &A, int s, int e) {
    int result = 0;
    for (int i = s;i <= e;i++) {
        result += A[i];
    }
    return result;
}

int stoneGame(vector<int> &A) {
    int n = A.size();
    if (n < 2) {
        return 0;
    }
    int dp[n][n];
    for (int i = 0;i < n;i++) {
        dp[i][i] = 0;
    }
    for (int l = 2;l <= n;l++) {
        for (int i = 0;i+l-1 < n;i++) {
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            int w = weight(A,i,j);
            for (int k = i;k < j;k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + w);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    int b[3] = {3,4,3};
    vector<int> test(b,b+3);
    /*int a = 0;
    vector<int> result = find_min(test,a);
    cout << "a : " << a << endl;
    result = find_min(result,a);
    cout << "a : " << a << endl;
    result = find_min(result,a);
    cout << "a : " << a << endl;
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }*/
    cout << stoneGame(test) << endl;
    return 0;
}
