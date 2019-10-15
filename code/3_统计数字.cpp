#include <iostream>
#include <cmath>
using namespace std;
// count the number of 5
int digitCounts(int k, int n) {
    int result = 0;
    if (k == 0) {
        result ++;
    }
    int num = 0;
    for (int i = 1;i <= n;i ++) {
        int count_n = 0;
        num = i;
        while (num != 0) {
            num /= 10;
            count_n ++;
        }
        num = i;
        for (int j = 0;j < count_n;j ++) {
            int temp = num/pow(10,count_n - j - 1);
            //cout << temp << " ";
            num = num - temp * pow(10,count_n - j - 1);
            if (temp == k) {
                result ++;
            }
        }
        //cout << endl;
    }
    return result;
}

int main() {
    int k,n;
    cin >> k >> n;
    cout << digitCounts(k,n) << endl;
    return 0;
}

