#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int find_num(vector<int> &A, int target) {
    int start = 0;
    int end = A.size() - 1;
    while (start < end) {
        int mid = (start + end)/2;
        if (target > A[mid]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return start;
}

vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
    if (A.size() == 0) {
        vector<int> result(queries.size(),0);
        return result;
    }
    vector<int> result;
    sort(A.begin(),A.end());
    for (int i = 0;i < queries.size();i++) {
        for (int j = 0;j < A.size();j++) {
            if (queries[i] <= A[0]) {
                result.push_back(0);
                break;
            }
            else if (queries[i] > A[A.size()-1]) {
                result.push_back(A.size());
                break;
            }
            result.push_back(find_num(A,queries[i]));
            break;
            /*if (A[j] >= queries[i]) {
                result.push_back(j);
                break;
            }*/
        }
    }
    return result;
}

int main() {
}
