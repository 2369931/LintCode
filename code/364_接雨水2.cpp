#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <limits>

using namespace std;

int trapRainWater(vector<vector<int> > &heights) {
    int n = heights.size();
    if (n == 0) return 0;
    int m = heights[0].size();
    int peek[n][m];
    queue<pair<int,int> > q;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (i == 0 || j == 0 || i == n-1 || j == m-1) {
                peek[i][j] = heights[i][j];
                q.push(make_pair(i,j));
            }
            else {
                peek[i][j] = INT_MAX;
            }
        }
    }
    while (!q.empty()) {
        pair<int,int> temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        int nx;
        int ny;
        for (int i = 0;i < 4;i++) {
            if (i == 0) {
                nx = x - 1;
                ny = y;
            }
            else if (i == 1) {
                nx = x;
                ny = y + 1;
            }
            else if (i == 2) {
                nx = x + 1;
                ny = y;
            }
            else if (i == 3) {
                nx = x;
                ny = y - 1;
            }
            if (nx <= 0 || nx >= n-1 || ny <= 0 || ny >= m-1) continue;
            int limit = max(peek[x][y], heights[nx][ny]);
            if (peek[nx][ny] > limit) {
                peek[nx][ny] = limit;
                q.push(make_pair(nx,ny));
            }
        }
    }
    int result = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            result += peek[i][j] - heights[i][j];
        }
    }
    return result;
}
