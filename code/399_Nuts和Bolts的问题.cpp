#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Comparator {
    public:
     int cmp(string a, string b);
};

void sortNutsAndBolts (vector<string> &nuts, vector<string> &bolts, Comparator compare) {
    int n = nuts.size();
    int m = bolts.size();
    if (n != m) {
        return;
    }
    if (m == 0) {
        return;
    }
    quicksort(nuts,bolts,compare,0,n-1);
}

void quicksort(vector<string> &nuts, vector<string> &bolts, Comparator compare,int start, int end) {
    if (start >= end) return;
    int index = partition(nuts,bolts[start],compare,start,end);
    partition(bolts,nuts[index],compare,start,end);

    quicksort(nuts,bolts,compare,start,index-1);
    quicksort(nuts,bolts,compare,index+1,end);
}

int partition (vector<string> &str, string temp, Comparator compare, int start, int end) {
    int m = start;
    for (int i = start + 1;i <= end;i++) {
        if (compare.cmp(temp, str[i]) == 1||compare.cmp(str[i],temp) == -1) {
            swap(str[++m],str[i]);
        }
        else if (compare.cmp(temp, str[i]) == 0||compare.cmp(str[i],temp) == 0) {
            swap(str[start],str[i]);
            --i;
        }
    }
    swap(str[m],str[start]);
    return m;
}
