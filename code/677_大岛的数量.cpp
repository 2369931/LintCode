#include <iostream>
#include <vector>
#include <string>

using namespace std;

int area = 0;

void dfs(vector<vector<bool>> &grid, int i, int j) {
    if(grid[i][j]==0) return;
    area ++;
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


int numsofIsland(vector<vector<bool>> &grid, int k) {
    int n = grid.size();
    int result = 0;
    if (n == 0) {
        return result;
    }
    int m = grid[0].size();
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (grid[i][j] == 1) {
                dfs(grid,i,j);
                if (area >= k)
                    result ++;
                area = 0;
            }
        }
    }
    return result;
}
