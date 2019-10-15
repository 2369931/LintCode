#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class interval {
public:
    int start;
    int end;
    interval() {}
    interval(int s, int t) {
        this->start = s;
        this->end = t;
    }
};

bool compare(interval &a, interval &b) {
    return a.start < b.start;
}

bool judge(vector<interval> &time) {
    int n = time.size();
    if (n == 0) {
        return false;
    }
    sort(time.begin(), time.end(), compare);
    int leave = 0;
    for (int i = 0;i < time.size();i++) {
        int mid = (time[i].end - time[i].start)/2 + 1;
        if (leave + mid > time[i].end) {
            return false;
        }
        else {
            leave = mid;
        }
    }
    return true;
}

int main() {
    interval a(0,5);
    interval b(3,5);
    interval c(5,8);
    interval d(8,10);
    vector<interval> test;
    test.push_back(b);
    test.push_back(d);
    test.push_back(c);
    test.push_back(a);
    cout << judge(test) << endl;
    return 0;
}
