#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> &pages, int n, int k) {
    int people = 0;
    int sum = 0;
    int flag = 0;
    for (int i = 0;i < pages.size();i++) {
        if (sum + pages[i] <= n) {
            sum += pages[i];
        }
        else if (pages[i] <= n) {
            people += 1;
            sum = pages[i];
        }
        else {
            return false;
        }
    }
    if (sum != 0) {
        //第一个人
        people ++;
    }
    return people <= k;
}

int copyBooks(vector<int> &pages, int k) {
    int n = pages.size();
    if (n == 0) {
        return 0;
    }
    int sum = 0;
    int max_book = -1;
    for (int i = 0;i < n;i++) {
        sum += pages[i];
        if (pages[i] > max_book) {
            max_book = pages[i];
        }
    }
    if (n == 1) {
        return sum;
    }
    if (n <= k) {
        return max_book;
    }
    int L = 0;
    int R = sum;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(pages,mid,k)) {
            R = mid;
        }
        else {
            L = mid + 1;
        }
    }
    return L;
}

int main() {
    int a[3] = {3,2,4};
    vector<int> test(a,a+3);
    cout << copyBooks(test,2) << endl;
    return 0;
}
