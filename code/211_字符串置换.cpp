#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

bool Permutation(string &A, string &B) {
    map<char, int> record_A;
    for (int i = 0;i < A.length();i++) {
        record_A[A[i]] ++;
    }
    map<char, int> record_B;
    for (int i = 0;i < B.length();i++) {
        record_B[B[i]] ++;
    }
    if (record_A.size() != record_B.size()) return false;
    map<char, int>::iterator it;
    for (it = record_A.begin();it != record_A.end();it++) {
        if (it->second != record_B[it->first]) {
            return false;
        }
    }
    return true;
}
