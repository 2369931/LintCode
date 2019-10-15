#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    vector<int> result;
    int i = 0;
    int j = 0;
    while (i < A.size()&& j < B.size()) {
        if (A[i] < B[j]) {
            result.push_back(A[i]);
            i++;
        }
        else {
            result.push_back(B[j]);
            j++;
        }
    }
    if (i == A.size()) {
        result.insert(result.end(),B.begin() + j,B.end());
    }
    else {
        result.insert(result.end(),A.begin() + i,A.end());
    }
    return result;
}

int main() {
    int a[4] = {1,2,3,4};
    vector<int> num_1(a,a+4);
    int b[7] = {2,4,5,6,7,8,99};
    vector<int> num_2(b,b+7);
    vector<int> result = mergeSortedArray(num_1,num_2);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
