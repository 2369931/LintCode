#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int> &numbers,int i,int j,int target) {

    if (i < 0 || i >= numbers.size() || j < 0 || j >= numbers.size() || i > j) {
        return -999999;
    }
    int mid = (i + j) / 2;
    if (numbers[mid] == target) {
        return numbers[mid];
    }
    else if (numbers[mid] > target) {
        find(numbers,i,mid-1,target);
    }
    else {
        find(numbers,mid+1,j,target);
    }
}
vector<int> twoSum(vector<int> &numbers, int target) {
    int start = 0;
    int end = 0;
    vector<int> record = numbers;
    sort(numbers.begin(),numbers.end());
    for (int i = 0;i < numbers.size();i++) {
        start = numbers[i];
        end = find(numbers,i+1,numbers.size()-1,target-numbers[i]);
        cout << start << " : " << end << endl;
        if (end != -999999) break;
    }
    vector<int> result;
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < record.size();i++) {
        if (start == record[i]) {
            index1 = i;
            break;
        }
    }
    for (int i = 0; i < record.size();i++) {
        if (end == record[i] && index1 != i) {
            index2 = i;
            break;
        }
    }
    if (index1 < index2) {
        start = index1;
        end = index2;
    }
    else {
        start = index2;
        end = index1;
    }
    result.push_back(start);
    result.push_back(end);
    return result;
}

int main() {
    int a[20] = {1,2,33,23,2423,33,23,1,7,6,8787,5,33,2,3,-23,-54,-67,100,400};
    vector<int> test(a,a+20);
    vector<int> result = twoSum(test,407);
    for (int i = 0;i < result.size();i ++) {
        cout << result[i] << " ";
    }
    return 0;
}
