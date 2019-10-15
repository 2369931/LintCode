#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class MovingAverage {
public:
    queue<int> record;
    long long sum;
    int number;
    MovingAverage(int size) {
        sum = 0;
        number = size;
    }

    double next(int val) {
        double res;
        int n = record.size();
        sum += val;
        if (n == number) {
            sum -= record.front();
            record.pop();
        }
        record.push(val);
        return (double)sum/record.size();

    }
};
