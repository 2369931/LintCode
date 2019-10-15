#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    //int n;
    //cin >> n;
    vector<string> test;
    string ss = "";
    getline(cin, ss);
    cout << ss << endl;
    string temp = "";
    for (int i = 0;i < ss.length();i++) {
        if (ss[i] != ' ') {
            temp += ss[i];
        }
        else {
            test.push_back(temp);
            temp = "";
        }
    }
    test.push_back(temp);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << endl;
    }
    return 0;
}
