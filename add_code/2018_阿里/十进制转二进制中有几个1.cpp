#include <iostream>

using namespace std;

int count_one (int n) {
    int count_number = 0;
    while (n) {
        count_number ++;
        n = n&(n-1);
    }
    return count_number;
}

int main() {
    cout << count_one(-5) << endl;
    return 0;
}
