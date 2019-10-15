#include <iostream>
#include <vector>

using namespace std;

int sum = 0;
int ds (const vector<NestedInteger>& nestedList, int deep) {
    for (int i = 0;i < nestedList.size();i++) {
        if (nestedList[i].isInteger()) {
            sum += deep * nestedList[i].getInteger();
        }
        else {
            ds(nestedList[i].getList(),deep+1);
        }
    }
}
int depthSum(const vector<NestedInteger>& nestedList) {
    ds(nestedList,deep);
    return sum;
}

