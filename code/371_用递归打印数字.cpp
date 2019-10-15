#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <limits>
#include <cmath>

using namespace std;

void calculate(vector<int> &result, int i, int n) {
    if (result.size() == n)
        return;
    else {
        result.push_back(i);
        i ++;
        calculate(result, i, n);
    }
}


vector<int> numbersByRecursion(int n) {
    vector<int> result;
    if (n == 0) return result;
    int size = pow(10,n);
    calculate(result,1,size-1);
    return result;
}

int main() {
    vector<int> test = numbersByRecursion(2);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << endl;
    }
    return 0;
}
