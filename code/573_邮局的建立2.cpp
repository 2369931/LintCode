#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class point{
public:
    int x;
    int y;
    point(int a,int b) {
        x = a;
        y = b;
    }
};

int WALL = 2;
int HOUSE = 1;
int EMPTY = 0;

bool isVaild(vector<vector<int> > &grid, int x, int y) {
    int n = grid.size();
    int m = grid[0].size();
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true;
    }
    else {
        return false;
    }
}

void bfs(vector<vector<int> > &grid,vector<vector<int> > &visited,vector<vector<int> > &path,point p) {
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    int n = grid.size();
    int m = grid[0].size();
    int record[n][m];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            record[i][j] = 0;
        }
    }
    queue<point> q;
    q.push(p);
    record[p.x][p.y] = 1;
    int steps = 0;
    while (!q.empty()) {
        int length = q.size();
        for (int i = 0;i < length;i++) {
            point top = q.front();
            q.pop();
            visited[top.x][top.y] ++;
            path[top.x][top.y] += steps;
            for (int j = 0;j < 4;j++) {
                point next(top.x + dx[j], top.y + dy[j]);
                if (isVaild(grid,next.x,next.y) && record[next.x][next.y] == 0 && grid[next.x][next.y] == EMPTY) {
                    q.push(next);
                    record[next.x][next.y] = 1;
                }
            }
        }
        steps ++;
    }
}

int shortestDistance(vector<vector<int> > &grid) {
    int n = grid.size();
    if (n == 0) {
        return 0;
    }
    int m = grid[0].size();
    vector<vector<int> > visited(n,vector<int>(m,0));
    vector<vector<int> > path(n,vector<int>(m,0));
    vector<point> house;
    int house_number = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (grid[i][j] == HOUSE) {
                point p(i,j);
                house.push_back(p);
                house_number ++;
            }
        }
    }
    for (int i = 0;i < house.size();i++) {
        bfs(grid,visited,path,house[i]);
    }
    int result = INT_MAX;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (grid[i][j] == EMPTY && visited[i][j] == house_number) {
                result = min(result,path[i][j]);
            }
        }
    }
    if (result == INT_MAX) {
        return -1;
    }
    else {
        return result;
    }
}

int main() {
    return 0;
}
