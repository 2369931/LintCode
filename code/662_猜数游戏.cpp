#include <iostream>

using namespace std;

int mid_find(long long s, long long e) {
    if (s <= e) {
        long long mid = (s + e)/2;
        int flag = guess(mid);
        if (flag == 0) {
            return (int)mid;
        }
        else if (flag == 1) {
            mid_find(mid+1,e);
        }
        else {
            mid_find(s,mid-1);
        }
    }
}

int guessNumber(int n) {
    return mid_find(1,n);
}
