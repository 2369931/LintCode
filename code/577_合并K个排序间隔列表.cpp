#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

bool judge(Interval a, Interval b) {
    if (a.start > b.end || b.start > a.end) {
        return false;
    }
    else {
        return true;
    }
}

Interval merge_interval(Interval a, Interval b) {
    Interval interval(min(a.start, b.start), max(a.end,b.end));
    return interval;
}

bool compare(Interval &a, Interval &b) {
    return a.start < b.start;
}

vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval> > &intervals) {
    vector<Interval> temp;
    for (int i = 0;i < intervals.size();i++) {
        for (int j = 0;j < intervals[i].size();j++) {
            temp.push_back(intervals[i][j]);
        }
    }
    sort(temp.begin(),temp.end(),compare);
    vector<Interval> result;
    for (int i = 0;i < temp.size();i++) {
        if (i+1 < temp.size() && judge(temp[i],temp[i+1])) {
            result.push_back(merge_interval(temp[i],temp[i+1]));
            i++;
        }
        else {
            result.push_back(temp[i]);
        }
    }
    return result;
}

int main() {
    Interval a(1,3);
    Interval b(4,7);
    Interval c(9,10);
    Interval d(11,12);
    Interval e(9,10);
    vector<Interval> test1;
    test1.push_back(a);
    test1.push_back(b);
    //test1.push_back(c);
    vector<Interval> test2;
    test2.push_back(c);
    test2.push_back(d);
    vector<vector<Interval> > test;
    test.push_back(test1);
    test.push_back(test2);
    vector<Interval> result = mergeKSortedIntervalLists(test);
    for (int i = 0;i < result.size();i++) {
        cout << " (" <<result[i].start << "," << result[i].end << "), ";
    }
    return 0;
}
