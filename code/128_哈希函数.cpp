#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <map>

using namespace std;

int hashCode(string &key, int HASH_SIZE) {
    int length = key.length();
    if (length == 0 || HASH_SIZE == 0) return 0;
    long long result = 0;
    for (int i = 0;i < length;i++) {
        result = result*33%HASH_SIZE + (int)(key[i]);
    }
    return result%HASH_SIZE;
}

int main() {
    string s = "abcd";
    cout << hashCode(s,100) << endl;
    return 0;
}
