#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>

using namespace std;

void swapIntegers(vector<int> &A, int index1, int index2) {
    int temp = A[index1];
    A[index1] = A[index2];
    A[index2] = temp;
}

