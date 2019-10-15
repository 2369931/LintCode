#include <iostream>
#include <vector>

using namespace std;

bool firstWillWin(int n) {
    if (n == 0) return false;
    if (((n-1)%3 == 0) || ((n-2)%3 == 0))
        return true;
    return false;
}
