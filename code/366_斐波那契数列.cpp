#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*int fibonacci(int n) {
    if (n == 1) return 0;
    else if (n == 2) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}*/

int fibonacci(int n) {
    if (n == 1) return 0;
    else if (n == 2) return 1;
    else {
        vector<int> record(n+1,0);
        record[1] = 0;
        record[2] = 1;
        for (int i = 3;i <= n;i++) {
            record[i] = record[i-1] + record[i-2];
        }
        return record[n];
    }
}

int main() {
    cout << fibonacci(41) << endl;
    return 0;
}

