#include <iostream>

using namespace std;

int findFirstBadVersion(int n) {
    int start = 1;
    int end = n;
    if (n == 1) return 1;
    //if (n == 2147483647) return 2147483647;
    if (SVNRepo::isBadVersion(n) && !SVNRepo::isBadVersion(n-1)) return n;
    while (start <= end) {
        int mid = (start + end)/2;
        if (!SVNRepo::isBadVersion(mid)) {
            start = mid + 1;
        }
        else {
            if (mid > 1 && !SVNRepo::isBadVersion(mid-1)) {
                return mid;
            }
            else {
                end = mid - 1;
            }
        }
    }
}
