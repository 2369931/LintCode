#include <iostream>
#include <vector>

using namespace std;

class Interval {
    public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

int countOfAirplanes(vector<Interval> &airplanes) {
    int n = airplanes.size();
    if (n == 0) {
        return 0;
    }
    int max_time = -1;
    for (int i = 0;i < n;i++) {
        if (max_time < airplanes[i].end) {
            max_time = airplanes[i].end;
        }
    }
    int dp[max_time+1];
    int record[max_time+1];
    for (int i = 0;i <= max_time;i++) {
        dp[i] = 0;
        record[i] = -1;
    }

    for (int i = 0;i < n;i++) {
        record[airplanes[i].start] = 0;
        record[airplanes[i].end] = 1;
        for (int j = airplanes[i].start;j <= airplanes[i].end;j++) {
            if (record[j] != 1) {
                dp[j] ++;
            }
            else {
                record[j] = -1;
            }
        }
    }

    int result = 0;
    for (int i = 0;i <= max_time;i++) {
        if (result < dp[i]) {
            result = dp[i];
        }
    }
    return result;
}

int main () {
    return 0;
}
