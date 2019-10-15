#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string &s) {
    int n = s.length();
    int result = 0;
    if (n == 0) {
        return 0;
    }
    for (int i = n - 1;i >= 0;i--) {
        if (s[i] == ' ' && result != 0) {
            break;
        }
        else if (s[i] != ' ') {
            result ++;
        }
    }
    return result;
}

int main() {
    string test = "a  ";
    cout << lengthOfLastWord(test) << endl;
    return 0;
}
