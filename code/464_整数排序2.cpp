#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int partion(vector<int> &record, int start, int end) {
    int n = end;
    int x = record[n];
    int i = start - 1;
    int temp = 0;
    for (int j = start;j < n;j++) {
        if (record[j] < x) {
            i ++;
            temp = record[i];
            record[i] = record[j];
            record[j] = temp;
        }
    }
    i++;
    temp = record[i];
    record[i] = record[n];
    record[n] = temp;
    return i;
}

void quicksort(vector<int> &record,int start, int end) {
    if (start < end) {
        int q = partion(record,start,end);
        quicksort(record,start,q-1);
        quicksort(record,q+1,end);
    }
}

void sortIntegers2(vector<int> &A) {
    int n = A.size();
    if (n == 0 || n == 1) {
        return;
    }
    quicksort(A,0,n-1);
}

int main() {
    int a[4] = {4,1,16,8};
    vector<int> test(a,a+4);
    sortIntegers(test);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << " ";
    }
    return 0;
}
