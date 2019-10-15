#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <map>

using namespace std;


void dfs (vector<string> &result, string &digits, vector<char> temp, map<char,string> &book, int n, int k) {
    if (temp.size() == n) {
        string str = "";
        for (int i = 0;i < temp.size();i++) {
            str += temp[i];
        }
        result.push_back(str);
    }
    else {
        for (int i = 0;i < book[digits[k]].length();i++) {
            temp.push_back(book[digits[k]][i]) ;
            dfs(result,digits,temp,book,n,k+1);
            temp.pop_back();
        }
    }
}

vector<string> letterCombinations(string &digits) {
    int n = digits.length();
    vector<string> result;
    if (n == 0) {
        return result;
    }
    map<char,string> book;
    book['2'] = "abc";
    book['3'] = "def";
    book['4'] = "ghi";
    book['5'] = "jkl";
    book['6'] = "mno";
    book['7'] = "pqrs";
    book['8'] = "tuv";
    book['9'] = "wxyz";
    vector<char> temp;
    dfs(result,digits,temp,book,n,0);
    return result;
}

int main() {
    string test = "234";
    vector<string> result = letterCombinations(test);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << endl;
    }
    return 0;
}
