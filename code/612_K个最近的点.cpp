#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
   int x;
   int y;
   Point() : x(0), y(0) {}
   Point(int a, int b) : x(a), y(b) {}
};

struct n_Point {
    Point p;
    int dis;
    n_Point(Point point, int d) {
        p = point;
        dis = d;
    }
};

static bool compare(n_Point &p, n_Point &q) {
    if (p.dis < q.dis) {
        return true;
    }
    else if (p.dis == q.dis) {
        if (p.p.x < q.p.x) {
            return true;
        }
        else if (p.p.x > q.p.x) {
            return false;
        }
        else if (p.p.x == q.p.x) {
            return p.p.y < q.p.y;
        }
    }
    else {
        return false;
    }
}

vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
    vector<Point> res;
    int n = points.size();
    if (n == 0) {
        return res;
    }
    vector<n_Point> record;
    for (int i = 0;i < n;i++) {
        int dis = (points[i].x - origin.x)*(points[i].x - origin.x)
        + (points[i].y - origin.y)*(points[i].y - origin.y);
        n_Point p(points[i],dis);
        record.push_back(p);
    }
    sort(record.begin(),record.end(),compare);
    for (int i = 0;i < k;i ++) {
        res.push_back(record[i].p);
    }
    return res;
}

int main() {
    return 0;
}
