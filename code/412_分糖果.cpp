#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*int candy(vector<int> &ratings) {
    int n = ratings.size();
    if (n == 0) {
        return 0;
    }
    int result[n];
    for (int i = 0;i < n;i++) {
        result[i] = 1;
    }
    for (int i = 0;i < ratings.size();i++) {
        int left = i - 1;
        int right = i + 1;
        if (left < 0) {
            if (ratings[right] < ratings[i] && result[right] >= result[i])
                result[i] = result[right] + 1;
        }
        else if (right >= n) {
            if (ratings[left] < ratings[i] && result[left] >= result[i])
                result[i] = result[left] + 1;
        }
        else {
            if (ratings[right] < ratings[i] && result[right] >= result[i])
                result[i] = result[right] + 1;
            if (ratings[left] < ratings[i] && result[left] >= result[i])
                result[i] = result[left] + 1;


        }
    }
    int sum = 0;
    for (int i = 0;i < n;i++) {
        cout << result[i] << endl;
        sum += result[i];
    }
    return sum;
}*/

int candy(vector<int> &ratings) {
    int n = ratings.size();
    if (n == 0) {
        return 0;
    }
    int result = 1;
    int precount = 1;
    int length = 0;
    int beforeDenc = precount;
    for (int i = 1;i < n;i++) {
        if (ratings[i] < ratings[i-1]) {
            length ++;
            if (beforeDenc <= length) {
                result ++;
            }
            result += length;
            precount = 1;
        }
        else {
            int curcount = 0;
            if (ratings[i] > ratings[i-1]) {
                curcount = precount + 1;
            }
            else {
                curcount = 1;
            }
            result += curcount;
            precount = curcount;
            length = 0;
            beforeDenc = curcount;
        }
    }
    return result;
}

int main() {
    int a[3] = {1,3,5};
    vector<int> test(a,a+3);
    cout << candy(test) << endl;
    return 0;
}
