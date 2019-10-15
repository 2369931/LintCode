#include <iostream>
#include <string>

using namespace std;

void sortLetters(string &chars) {
   string result = "";
   for (int i = 0;i < chars.length();i++) {
        if (chars[i] >= 'a' && chars[i] <= 'z') {
            result = chars[i] + result;
        }
        else {
            result = result + chars[i];
        }
   }
   chars = result;
}

int main() {
    string test = "abAcD";
    sortLetters(test);
    cout << test << endl;
    return 0;
}
