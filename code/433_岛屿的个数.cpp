#include <iostream>
#include <cmath>
#include <limits>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<bool>> &grid, int i, int j) {
    if(grid[i][j]==0) return;
    grid[i][j] = 0;
    if (i > 0)
        dfs(grid,i-1,j);
    if (j > 0)
        dfs(grid,i,j-1);
    if (i < grid.size()-1)
        dfs(grid,i+1,j);
    if (j < grid[0].size()-1)
        dfs(grid,i,j+1);
}

int numIslands(vector<vector<bool>> &grid) {
    int n = grid.size();
    int result = 0;
    if (n == 0) {
        return result;
    }
    int m = grid[0].size();
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (grid[i][j] == 1) {
                result ++;
                dfs(grid,i,j);
            }
        }
    }
    return result;
}
