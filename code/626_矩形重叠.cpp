#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

bool doOverlap(Point &l1, Point &r1, Point &l2, Point &r2) {
    int l_1 = r1.x - l1.x;
    int h_1 = l1.y - r1.y;
    int l_2 = r2.x - l2.x;
    int h_2 = l2.y - r2.y;
    int l_mix_1 = r2.x - l1.x;
    l_mix_1 = abs(l_mix_1);
    int l_mix_2 = r1.x - l2.x;
    l_mix_2 = abs(l_mix_2);
    int h_mix_1 = l1.y - r2.y;
    h_mix_1 = abs(h_mix_1);
    int h_mix_2 = l2.y - r1.y;
    h_mix_2 = abs(h_mix_2);
    if (max(l_mix_1,l_mix_2) <= l_1 + l_2 && max(h_mix_1,h_mix_2) <= h_1 + h_2) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    Point l1(9,6);
    Point r1(10,0);
    Point l2(0,8);
    Point r2(8,0);
    cout << doOverlap(l1,r1,l2,r2) << endl;
    return 0;
}
