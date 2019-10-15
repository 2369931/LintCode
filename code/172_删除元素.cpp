#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &A, int elem) {
    int result = A.size();
    for (int i = 0;i < A.size();i++) {
        if (A[i] == elem) {
            result--;
            A.erase(A.begin()+i);
            i--;
        }
    }
    return result;
}

int main(){
    //int a[6] = {1,2,2,3,4,4};
    int a[1] = {2};
    vector<int> test(a,a+1);
    removeElement(test, 3);
    for (int i = 0;i < test.size();i++) {
        cout << test[i] << " ";
    }
    return 0;
}
