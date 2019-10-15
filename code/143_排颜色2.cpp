#include <iostream>
#include <vector>

using namespace std;
///using another space
void sortColors2(vector<int> &colors, int k) {
    int record[k+1];
    vector<int> rec_colors;
    for (int i = 0;i <= k;i++) {
        record[i] = 0;
    }
    for (int i = 0;i < colors.size();i++) {
        record[colors[i]] ++;
    }
    for (int i = 1;i < k+1;i ++) {
        for (int j = 0;j < record[i];j++) {
            rec_colors.push_back(i);
        }
    }
    for (int i = 0;i < colors.size();i++) {
        colors[i] = rec_colors[i];
    }
}
///not using another space
void sortColors2(vector<int> &colors, int k) {
    int n = colors.size();
    if (n <= 0) return;
    int index = 0;
    while (index < n) {
        int temp = colors[index] - 1;
        if (colors[index] <= 0) {
            index ++;
        }
        else {
            if (colors[temp] <= 0) {
                colors[temp] --;
                colors[index] = 0;
                index ++;
            }
            else {
                swap(colors[temp],colors[index]);
                colors[temp] = -1;
            }
        }
    }
    int i = n - 1;
    while (k > 0) {
        for (int j = 0;j > colors[k-1];j--) {
            colors[i--] = k;
        }
        k --;
    }
}

int main() {
    int a[5] = {3,2,2,1,4};
    vector<int> test(a,a+5);
    sortColors2(test,4);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << " ";
    }
    return 0;
}
