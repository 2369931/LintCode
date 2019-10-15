#include <iostream>
#include <vector>

using namespace std;

long long houseRobber(vector<int> &A) {
    int n = A.size();
    if (n == 0) {
        return 0;
    }
    long long value_yes = A[0];
    long long value_no = 0;
    for (int i = 1;i < n;i++) {
        long long temp = value_no;
        value_no = max (value_no,value_yes);
        value_yes = temp + A[i];
    }
    return max(value_yes,value_no);
}

int main() {

}

