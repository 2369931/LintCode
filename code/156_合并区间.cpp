#include <iostream>
#include <vector>
#include <limits>

using namespace std;

classs Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
}

bool cmp(const Interval &a, const Interval &b) {
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    if(intervals.size() == 0) {
        return result;
    }
    else if (intervals.size() == 1) {
        return intervals;
    }
    sort(intervals.begin(),intervals.end(),cmp);
    result.push_back(intervals[0]);
    for (int i = 1;i < intervals.size();i++) {
        Interval temp = result[result.size()-1];
        if (temp.end < intervals[i].start || intervals[i].end < temp.start) {
            result.push_back(intervals[i]);
        }
        else {
            Interval new_intervals;
            new_intervals.start = min(temp.start, intervals[i].start);
            new_intervals.end = max(temp.end, intervals[i].end);;
            result.pop_back();
            result.push_back(new_intervals);
        }
    }
    return result;
}
