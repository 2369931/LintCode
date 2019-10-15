#include <iostream>
#include <string>
#include <vector>

using namespace std;

string spilt(string str, int s, int k) {
    string result = "";
    for (int i = s;i <= k;i++) {
        result += str[i];
    }
    return result;
}

bool inTargetNoChange(string target, char temp) {
    for (int i = 0;i < target.length();i++) {
        if (target[i] == temp) {
            return true;
        }
    }
    return false;
}

bool inTarget(string &target, char temp) {
    for (int i = 0;i < target.length();i++) {
        if (target[i] == temp) {
            string s1 = "";
            string s2 = "";
            if (i-1 >= 0) {
                s1 = spilt(target,0,i-1);
            }
            if (i+1 <= target.length()-1) {
                s2 = spilt(target,i+1,target.length()-1);
            }
            target = s1 + s2;
            return true;
        }
    }
    return false;
}

string minWindow(string &source , string &target) {
    if (target == "" || source == "") {
        return "";
    }
    vector<int> start;
    int flag = 0;
    for (int i = 0;i < source.length();i++) {
        if (inTargetNoChange(target,source[i]) && source.length() - i >= target.length()) {
            start.push_back(i);
        }
    }
    int min_length = 999999;
    int s = 0;
    int k = 0;
    string record = target;
    for (int i = 0;i < start.size();i++) {
        target = record;
        for (int j = start[i];j < source.length();j++) {
            inTarget(target,source[j]);
            if (target == "") {
                flag = 1;
                if (j - start[i] + 1 < min_length) {
                    s = start[i];
                    k = j;
                    min_length = k - s + 1;
                }
                break;
            }
        }
    }
    if (flag == 1) {
        return spilt(source,s,k);
    }
    else {
        return "";
    }
}

int main() {
    string source = "adfqeradboaf23098724huhfda923hadf78adfhadfhadfaodiyfas8";
    string target = "dfje89affefy8f";
    cout << minWindow(source,target) << endl;
    return 0;
}
