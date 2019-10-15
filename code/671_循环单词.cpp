#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool judge(string a, string b) {
    int n = a.length();
    int m = b.length();
    if (n != m) {
        return false;
    }
    else {
        if (a == b) {
            return true;
        }
        string temp = a + a;
        if (temp.find(b) != string::npos) {
            return true;
        }
        else {
            return false;
        }
    }
}

int countRotateWords(vector<string> words) {
    int n = words.size();
    if (n == 0 || n == 1) {
        return n;
    }
    vector<int> record(n,0);
    int res = n;
    for (int i = 0;i < n;i ++) {
        if (record[i] == 0) {
           for (int j = i + 1;j < n;j++) {
                if (judge(words[i],words[j])) {
                    record[j] = 1;
                    res --;
                }
            }
        }
    }
    return res;
}

int main() {
    /*string a = "picture";
    string b = "icturep";
    cout << judge(a,b) << endl;*/
    string a[6] = {"picture", "turepic", "icturep", "word", "ordw", "lint"};
    vector<string> test(a,a+6);
    cout << countRotateWords(test) << endl;
    return 0;
}

