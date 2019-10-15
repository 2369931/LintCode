#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <map>

using namespace std;

void process(vector<string> &result,string temp, int left, int right, int n) {
    if (left > n || right > n || left < right) {
        return;
    }
    if (left == n && right == n) {
        result.push_back(temp);
        return;
    }
    process(result,temp+"(",left+1,right,n);
    process(result,temp+")",left,right+1,n);
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    if (n <= 0) {
        return result;
    }
    string temp = "";
    process(result,temp,0,0,n);
    return result;
}

int main() {
    vector<string> result = generateParenthesis(3);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << endl;
    }
    return 0;
}
