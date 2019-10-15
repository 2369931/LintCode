#include <iostream>
#include <string>

using namespace std;

string leftPad(string &originalStr, int size, char padChar=' ') {
    if (originalStr.length() >= size) {
        return originalStr;
    }
    else {
        while (originalStr.length() < size) {
            originalStr = padChar + originalStr;
        }
        return originalStr;
    }
}

int main() {
    string test = "foo";
    cout << leftPad(test,5,' ') << endl;
    return 0;
}
