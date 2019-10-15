#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


vector<int> grayCode(int n) {
    vector<int> result;
    if (n == 0) {
        result.push_back(0);
        return result;
    }
    if (n == 1) {
        result.push_back(0);
        result.push_back(1);
        return result;
    }
    vector<int> last_grayCode = grayCode(n-1);
    for (int i = 0;i < last_grayCode.size();i++) {
        result.push_back(last_grayCode[i]);
    }
    for (int i = last_grayCode.size()-1;i >= 0;i--) {
        result.push_back(pow(2,n-1) + last_grayCode[i]);
    }
    return result;
}

int main() {
    vector<int> result = grayCode(3);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << endl;
    }
    return 0;
}

