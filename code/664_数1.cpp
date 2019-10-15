#include <iostream>
#include <vector>

using namespace std;

int count_one(int num) {
    int res = 0;
    while(num) {
        num = num&(num-1);
        res++;
    }
    return res;
}

vector<int> countBits(int num) {
    vector<int> res;
    for (int i = 0;i <= num;i++) {
        res.push_back(count_one(i));
    }
    return res;
}

int main() {
    vector<int> res = countBits(5);
    for (int i = 0;i <= 5;i++) {
        cout << res[i] << " ";
    }
    return 0;
}
