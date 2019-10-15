#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string int_to_str(int temp) {
    string result = "";
    stringstream ss;
    ss << temp;
    ss >> result;
    ss.clear();
    return result;
}

static bool compare(string &A, string &B) {
//bool compare(string A, string B){
    if (A == B) return false;
    int n = A.length();
    int m = B.length();
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (A[i] > B[j]) {
            return true;
        }
        else if (A[i] < B[j]) {
            return false;
        }
        else {
            if (i+1 == n && j+1 == m) {
                return false;
            }
            if (i+1 < n) {
                i++;
            }
            if (j+1 < m) {
                j++;
            }
        }
    }
    return false;
}

void check(string &A) {
    while (A[0] == '0' && A.length() > 1) {
        A = A.substr(1,A.length());
    }
}

string largestNumber(vector<int> &nums) {
    int n = nums.size();
    string result = "";
    if (n == 0) return result;
    vector<string> record;
    for (int i = 0;i < n;i++) {
        record.push_back(int_to_str(nums[i]));
    }
    sort(record.begin(),record.end(),compare);
    for (int i = 0;i < n;i++) {
        result += record[i];
    }
    check(result);
    return result;
}

int main() {
    //cout << compare("99", "9") << endl;
    int a[100] = {25,5,12,97,3,8,79,73,38,88,98,29,84,74,16,2,67,65,41,44,88,75,51,87,95,90,45,40,7,53,5,30,77,5,56,58,41,51,62,88,33,69,81,78,18,63,82,90,21,6,12,92,67,6,81,83,14,6,76,85,79,96,41,44,20,89,59,58,83,58,73,1,41,41,24,55,61,49,10,42,5,1,98,30,91,9,34,5,84,43,73,4,22,11,21,14,1,62,77,41};
    vector<int> test(a,a+100);
    cout << largestNumber(test) << endl;
    return 0;
}
