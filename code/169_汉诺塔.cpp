#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(vector<string> &result, int n, string from, string buffer, string to) {
    if (n == 1) {
        result.push_back("from " + from + " to " + to);
        return;
    }
    solve(result,n-1,from,to,buffer);
    result.push_back("from " + from + " to " + to);
    solve(result,n-1,buffer,from,to);
}

vector<string> towerOfHanoi(int n) {
    vector<string> result;
    solve(result, n, "A", "B", "C");
    return result;
}

int main() {
}
