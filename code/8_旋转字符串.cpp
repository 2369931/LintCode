#include <iostream>
#include <string>

using namespace std;

void rotateString(string &str, int offset) {
    if (offset == 0 || str == "")
        return;
    int length = str.length();
    offset = offset % length;
    char temp;
    for(int i = 0;i < offset;i ++) {
        temp = str[length-1];
        for(int j = length - 1;j > 0 ;j --) {
            str[j] = str[j-1];
        }
        str[0] = temp;
    }
    //str = str.substr(length - offset,length) + str.substr(0,length - offset);
}

int main() {
    int n = 2;
    string str = "abcdefg";
    cout << str.substr(0,1) << endl;
    rotateString(str,n);
    cout << str << endl;
    return 0;
}

