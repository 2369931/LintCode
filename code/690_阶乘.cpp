#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string intToString(int n) {
    stringstream ss;
    ss << n;
    string res = "";
    ss >> res;
    return res;
}

string factorial(int n) {
    if (n == 0) {
        return "1";
    }
    vector<int> res(200000, 0);
    res[0] = 1;
    int number = 1;
    for (int i = 1; i <= n;i++) {
        int flag = 0;
        for (int j = 0;j < number;j++) {
            int temp = i * res[j] + flag;
            res[j] = temp % 10;
            flag = temp / 10;
        }
        while (flag != 0) {
            res[number] = flag%10;
            number ++;
            flag /= 10;
        }
    }
    string result = "";
    for (int i = 0;i < number;i++) {
        result = intToString(res[i]) + result;
    }
    return result;
}

int main() {
    cout << factorial(2000) << endl;
    return 0;
}
