#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static bool comp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

int scheduleCourse(vector<vector<int> > &courses) {
    int n = courses.size();
    if (n == 0) {
        return 0;
    }
    sort(courses.begin(), courses.end(), comp);
    priority_queue<int> q;
    int time = 0;
    for (int i = 0;i < n;i++) {
        if (time + courses[i][0] <= courses[i][1]) {
            q.push(courses[i][0]);
            time += courses[i][0];
        }
        else if (!q.empty() && courses[i][0] < q.top()) {
            time += courses[i][0] - q.top();
            q.pop();
            q.push(courses[i][0]);
            //cout << time << " " << q.size() << endl;
        }
    }
    return q.size();
}

int main() {
    int s_a[2] = {5,5};
    vector<int> a(s_a, s_a+2);
    int s_b[2] = {4,6};
    vector<int> b(s_b, s_b+2);
    int s_c[2] = {2,6};
    vector<int> c(s_c, s_c+2);
    //int s_d[2] = {2000,3200};
    //vector<int> d(s_d, s_d+2);
    vector<vector<int> > test;
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);
    //test.push_back(d);
    cout << scheduleCourse(test) << endl;;
    return 0;
}
