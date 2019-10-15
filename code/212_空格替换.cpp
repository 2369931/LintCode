#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int replaceBlank(char string[], int length) {
    int result = 0;
    for (int i = 0;i < length;i++) {
        if (string[i] == ' ') {
            result ++;
        }
    }
    int newlength =  (length - result) + 3 * result;
    int index = newlength - 1;
    for (int i = length-1;i >= 0;i--) {
        if (string[i] == ' ') {
            string[index] = '0';
            index --;
            string[index] = '2';
            index --;
            string[index] = '%';
            index --;
        }
        else {
            string[index] = string[i];
            index --;
        }
    }
    return newlength;
}


