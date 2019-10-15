#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int num) {
    vector<int> record;
    while(num) {
        record.push_back(num%10);
        num = num/10;
    }
    int n = record.size();
    if (n == 1) {
        return true;
    }
    int s = 0;
    int e = n-1;
    while(s < e) {
        if (record[s] != record[e]) {
            return false;
        }
        s ++;
        e --;
    }
    return true;
}

int main() {
    cout << isPalindrome(1223221) << endl;
    return 0;
}
