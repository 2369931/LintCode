#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

vector<string> longestWords(vector<string> &dictionary) {
    int n = dictionary.size();
    vector<string> result;
    if (n == 0) {
        return result;
    }
    int max_length = 0;
    for (int i = 0;i < n;i ++) {
        int temp = dictionary[i].length();
        if (temp > max_length) {
            max_length = temp;
            result.clear();
            result.push_back(dictionary[i]);
        }
        else if (temp == max_length) {
            result.push_back(dictionary[i]);
        }
    }
    return result;
}

int main() {
}
