#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point> &points) {
    int n = points.size();
    if (n <= 2) return n;
    int result = 0;
    for (int i = 0;i < n; i++) {
        int same_point = 0;
        int same_x = 1;
        map<double,int> record;
        map<double,int>::iterator it;
        for (int j = 0; j < n;j ++) {
            if (i != j) {
                if ((points[j].y == points[i].y) && (points[j].x == points[i].x)) {
                    same_point ++;
                }
                if (points[j].x == points[i].x) {
                    same_x ++;
                    continue;
                }
                double k = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                it = record.find(k);
                if (it != record.end()) {
                    record[k] ++;
                }
                else {
                    record[k] = 2;
                }
                result = max(record[k] + same_point, result);
            }
        }
        result = max(result,same_x);
    }
    return result;
}

int main() {
}
