#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double cosineSimilarity(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    if (n != m || n == 0 || m == 0) {
        return 2.0000;
    }
    int sum_a = 0;
    for (int i = 0;i < n;i++) {
        sum_a += A[i] * B[i];
    }
    int sum_b = 0;
    int sum_c = 0;
    for (int i = 0;i < n;i++) {
        sum_b += A[i] * A[i];
        sum_c += B[i] * B[i];
    }
    if (sum_b == 0 || sum_c == 0) {
        return 2.0000;
    }
    return (double)sum_a/(sqrt(sum_b) * sqrt(sum_c));
}

int main() {
    return 0;
}
