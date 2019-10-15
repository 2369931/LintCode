#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void startfromgate(vector<vector<int> > &rooms, int n, int m, int x, int y, int distance) {
    if (x >=0 && x < n && y >=0 && y < m && rooms[x][y] >= distance) {
        rooms[x][y] = min(rooms[x][y],distance);
        startfromgate(rooms,n,m,x+1,y,distance+1);
        startfromgate(rooms,n,m,x-1,y,distance+1);
        startfromgate(rooms,n,m,x,y+1,distance+1);
        startfromgate(rooms,n,m,x,y-1,distance+1);
    }
    else {
        return;
    }
}

void wallsAndGates(vector<vector<int> > &rooms) {
    int n = rooms.size();
    if (n == 0) {
        return;
    }
    int m = rooms[0].size();
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (rooms[i][j] == 0) {
                startfromgate(rooms,n,m,i,j,0);
            }
        }
    }
}

int main() {
    int a[4] = {2147483647,-1,0,2147483647};
    vector<int> aa(a,a+4);
    int b[4] = {2147483647,2147483647,2147483647,-1};
    vector<int> bb(b,b+4);
    int c[4] = {2147483647,-1,2147483647,-1};
    vector<int> cc(c,c+4);
    int d[4] = {0,-1,2147483647,2147483647};
    vector<int> dd(d,d+4);
    vector<vector<int> > test;
    test.push_back(aa);
    test.push_back(bb);
    test.push_back(cc);
    test.push_back(dd);
    wallsAndGates(test);
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            cout << test[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
