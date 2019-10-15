#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

/*bool judge(vector<vector<bool> > &matrix, int x, int y, int a, int b) {
    for (int i = x;i < x + a;i++) {
        for (int j = y;j < y + b;j++) {
            if (matrix[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int maximalRectangle(vector<vector<bool> > &matrix) {
    int n = matrix.size();
    if (n == 0) {
        return 0;
    }
    int max_value = 0;
    int m = matrix[0].size();
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (matrix[i][j] == 1) {
                int a = 1;
                int b = 1;
                int x = i+1;
                int y = j+1;
                while (x < n) {
                    if (matrix[x][j] == 1) {
                        a ++;
                        x ++;
                    }
                    else {
                        break;
                    }
                }
                while (y < m) {
                    if (matrix[i][y] == 1) {
                        b ++;
                        y ++;
                    }
                    else {
                        break;
                    }
                }
                if (judge(matrix,i,j,a,b)) {
                    max_value = max(max_value,a*b);
                }
            }
        }
    }
    return max_value;
}*/

int maximalRectangle(vector<vector<bool>> &matrix) {

    if (matrix.empty())
        return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> v(row, vector<int>(col, 0));
    for (int j = 0; j < col; ++j)
    {
        for (int i = 0; i < row; ++i)
        {
            if (matrix[i][j])
            {
                v[i][j] = 1;
                if (i>0)
                    v[i][j] += v[i - 1][j];
            }
        }
    }
    int area = 0;
    for (auto &c : v)
    {
        area = maxVal(largestRectangleArea(c), area);
    }
    return area;
}
int largestRectangleArea(vector<int> &height) {
    int res = 0;
    stack<int> s;
    height.push_back(0);
    for (int i = 0; i < height.size(); ++i) {
        if (s.empty() || height[s.top()] < height[i]) s.push(i);
        else {
            int cur = s.top();
            s.pop();
            res = maxVal(res, height[cur] * (s.empty() ? i : (i - s.top() - 1)));
            --i;
        }
    }
    return res;
}
int maxVal(int a, int b)
{
    return a > b ? a : b;
}

int main() {
    return 0;
}
