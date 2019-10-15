#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<char> > &image, vector<vector<int> > &record, vector<int> &result, int n, int m, int x, int y) {
    if (record[x][y] == 0 && image[x][y] == '1') {
        record[x][y] = 1;
        if (x < result[0]) {
            result[0] = x;
        }
        if (x > result[1]) {
            result[1] = x;
        }
        if (y < result[2]) {
            result[2] = y;
        }
        if (y > result[3]) {
            result[3] = y;
        }
        if (x - 1 >= 0)
            dfs(image,record,result,n,m,x-1,y);
        if (x + 1 < n)
            dfs(image,record,result,n,m,x+1,y);
        if (y - 1 >= 0)
            dfs(image,record,result,n,m,x,y-1);
        if (y + 1 < m)
            dfs(image,record,result,n,m,x,y+1);
    }
    else {
        return;
    }
}

int minArea(vector<vector<char> > &image, int x, int y) {
    int n = image.size();
    if (n == 0) {
        return 0;
    }
    int m = image[0].size();
    vector<vector<int> > record(n,vector<int>(m,0));
    vector<int> result(4,0);
    result[0] = INT_MAX;
    result[2] = INT_MAX;
    dfs(image,record,result,n,m,x,y);
    /*for (int i = 0 ;i < 4;i++) {
        cout << result[i] << endl;
    }*/
    int a = result[1] - result[0] + 1;
    int b = result[3] - result[2] + 1;
    return a*b;
}

int main() {
    vector<vector<char> > image(3,vector<char>(4,'0'));
    //image[0][2] = '1';
    image[1][1] = '1';
    image[1][3] = '1';
    //image[2][1] = '1';
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 4;j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    cout << minArea(image,1,1) << endl;
    return 0;
}
