#include <iostream>
#include <vector>

using namespace std;

void change(vector<int> & vec) {
    int n = vec.size();
    if (n == 0) {
        return;
    }
    int k = -1;
    for (int i = 0;i < n;i++) {
        if (vec[i] % 2 == 0) {
            k = i;
            break;
        }
    }
    for (int i = 0;i < n;i++) {
        if (vec[i] % 2 == 1 && i > k && k != -1) {
            int temp = vec[i];
            vec[i] = vec[k];
            vec[k] = temp;
            k = i;
        }
    }
}

int main() {
    int a[6] = {1,2,3,4,5,6};
    vector<int> test(a,a+6);
    change(test);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << " ";
    }
    return 0;
}
