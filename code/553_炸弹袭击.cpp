#include <iostream>
#include <vector>

using namespace std;

int maxKilledEnemies(vector<vector<char>> &grid) {
    // write your code here
    if (grid.empty() || grid[0].empty())
        return 0;
    int rows = grid.size();
    int cols = grid[0].size();
    //up[i][j],down[i][j],left[i][j],right[i][j]分别表示grid[i-1][j-1]上下左右四个方向上可以杀死的敌人数
    vector<vector<int>>
        left(rows + 2, vector<int>(cols + 2, 0)),
        right(rows + 2, vector<int>(cols + 2, 0)),
        up(rows + 2, vector<int>(cols + 2, 0)),
        down(rows + 2, vector<int>(cols + 2, 0));
    //left[i][j]表示在grid[i-1][j-1]放置炸弹,向左可以杀死的最大敌人数
    //假设E也可以放置炸弹,当前元素为E,可以杀死的敌人数加一
    //当前元素为W,不能放置炸弹,可以杀死的人数为0
    //当前元素为0,可以杀死的人数不变
    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= cols; ++j)
        {
            if (grid[i - 1][j - 1] == 'E')
                left[i][j] = left[i][j - 1] + 1;
            else if (grid[i - 1][j - 1] == 'W')
                left[i][j] = 0;
            else
                left[i][j] = left[i][j - 1];
        }
    }
    //right[i][j]表示在grid[i - 1][j - 1]放置炸弹, 向右可以杀死的最大敌人数
    for (int i = 1; i <= rows; ++i)
    {
        for (int j = cols; j >= 1; --j)
        {
            if (grid[i - 1][j - 1] == 'E')
                right[i][j] = right[i][j + 1] + 1;
            else if (grid[i - 1][j - 1] == 'W')
                right[i][j] = 0;
            else
                right[i][j] = right[i][j + 1];
        }
    }
    //up[i][j]表示在grid[i-1][j-1]放置炸弹,向上可以杀死的最大敌人数
    for (int j = 1; j <= cols; ++j)
    {
        for (int i = 1; i <= rows; ++i)
        {
            if (grid[i - 1][j - 1] == 'E')
                up[i][j] = up[i-1][j] + 1;
            else if (grid[i - 1][j - 1] == 'W')
                up[i][j] = 0;
            else
                up[i][j] = up[i - 1][j];
        }
    }
    //down[i][j]表示在grid[i-1][j-1]放置炸弹,向下可以杀死的最大敌人数
    for (int j = 1; j <= cols; ++j)
    {
        for (int i = rows; i >= 1; --i)
        {
            if (grid[i - 1][j - 1] == 'E')
                down[i][j] = down[i + 1][j] + 1;
            else if (grid[i - 1][j - 1] == 'W')
                down[i][j] = 0;
            else
                down[i][j] = down[i + 1][j];
        }
    }
    int res = 0;
    //仅在grid[i-1][j-1]为0时计算其上下左右可以杀死敌人的总数
    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= cols; ++j)
        {
            if (grid[i - 1][j - 1] == '0')
            {
                res = max(res, left[i][j] + right[i][j] + up[i][j] + down[i][j]);
            }
        }
    }
    return res;
}

    /*int result = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (grid[i][j] == '0') {
                int sum = 0;
                int temp = i + 1;
                while (temp < n) {
                    if (grid[temp][j] == 'E') {
                        sum ++;
                        temp ++;
                    }
                    else if (grid[temp][j] == '0') {
                        temp ++;
                    }
                    else {
                        break;
                    }
                }
                temp = i - 1;
                while (temp >= 0) {
                   if (grid[temp][j] == 'E') {
                        sum ++;
                        temp --;
                    }
                    else if (grid[temp][j] == '0') {
                        temp --;
                    }
                    else {
                        break;
                    }
                }
                temp = j + 1;
                while (temp < m) {
                    if (grid[i][temp] == 'E') {
                        sum ++;
                        temp ++;
                    }
                    else if (grid[i][temp] == '0') {
                        temp ++;
                    }
                    else {
                        break;
                    }
                }
                temp = j - 1;
                while (temp >= 0) {
                    if (grid[i][temp] == 'E') {
                        sum ++;
                        temp --;
                    }
                    else if (grid[i][temp] == '0') {
                        temp --;
                    }
                    else {
                        break;
                    }
                }
                result = max(result,sum);
            }
        }
    }
    return result;*/
