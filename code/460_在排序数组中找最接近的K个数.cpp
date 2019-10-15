#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

/*int partion(vector<int> &record, int start, int end) {
    int n = end;
    int x = record[n];
    int i = start - 1;
    int temp = 0;
    for (int j = start;j < n;j++) {
        if (abs(record[j]) < abs(x)) {
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

void findtopk(vector<int> &record, vector<int> &result,int start, int end, int k, int t_k) {
    //cout << start << " : " << end << endl;
    if (start < end) {
        int q = partion(record,start,end);
        int i = q - start + 1;
        //cout << i << endl;
        if (i == k) {
            for (int j = 0;j < t_k;j++) {
                result.push_back(record[j]);
            }
            return;
        }
        else if (i > k) {
            findtopk(record,result,start,q-1,k,t_k);
        }
        else if (i < k){
            findtopk(record,result,q+1,end,k-i,t_k);
        }
    }

}

vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
    int n = A.size();
    vector<int> result;
    if (n == 0) {
        return result;
    }
    vector<int> record;
    for (int i = 0;i < n;i++) {
        record.push_back(A[i] - target);
    }
    findtopk(record,result,0,n-1,k,k);
    for (int i = 0;i < result.size()-1;i++) {
        if (abs(result[i]) == abs(result[i+1])&&result[i] > result[i+1]) {
            int temp = result[i+1];
            result[i+1] = result[i];
            result[i] = temp;
        }
    }
    //
    for (int i = 0;i < result.size();i++)
        result[i] += target;
    return result;
}*/

int find_best(vector<int> &A,int target) {
    int min_value = INT_MAX;
    int index = 0;
    for (int i = 0;i < A.size();i++) {
        if (min_value > abs(A[i] - target)) {
            min_value = abs(A[i] - target);
            index = i;
        }
    }
    return index;
}

vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
    int n = A.size();
    vector<int> result;
    if (n == 0 || k == 0) {
        return result;
    }
    int index = find_best(A,target);
    result.push_back(A[index]);
    int i = index - 1;
    int j = index + 1;
    while (result.size() < k) {
        int a = INT_MAX;
        int b = INT_MAX;
        if (i > -1)
            a = abs(A[i] - target);
        if (j < n)
            b = abs(A[j] - target);
        if (a <= b) {
            result.push_back(A[i]);
            i --;
        }
        else {
            result.push_back(A[j]);
            j ++;
        }
    }
    return result;
}

int main() {
    int a[4] = {1,4,6,8};
    vector<int> test(a,a+4);
    vector<int> result = kClosestNumbers(test,3,3);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    return 0;
}
