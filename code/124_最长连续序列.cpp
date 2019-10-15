#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <map>

using namespace std;

int merge (map<int,int> &record, int p, int q) {
    int left = p - record[p] + 1;
    int right = q + record[q] - 1;
    int length = right - left + 1;
    record[left] = length;
    record[right] = length;
    return length;
}

int longestConsecutive(vector<int> &num) {
    int n = num.size();
    if (n == 0 || n == 1) {
        return n;
    }
    map<int,int> record;
    int result = 1;
    for (int i = 0;i < n;i++) {
        if (record.find(num[i]) == record.end()) {
            record[num[i]] = 1;
            if (record.find(num[i]-1) != record.end()) {
                result = max(result,merge(record,num[i]-1,num[i]));
            }
            if (record.find(num[i]+1) != record.end()) {
                result = max(result,merge(record,num[i],num[i]+1));
            }
        }
    }
    return result;
}

int main() {
    int a[6] = {100,4,200,1,3,2};
    vector<int> test(a,a+6);
    cout << longestConsecutive(test) << endl;
    return 0;
}
