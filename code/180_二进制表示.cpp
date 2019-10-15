#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

void add(vector<int>& nums) {
    for (int i = 1;i < nums.size();i++) {
        if (nums[i] == 1) nums[i] = 0;
        else nums[i] = 1;
    }
    int n = nums.size() - 1;
    if (nums[n] == 0) {
        nums[n] = 1;
    }
    else {
        nums[n] = 0;
        int flag = 1;
        for (int i = nums.size()-2;i >= 1;i--) {
            int temp = flag + nums[i];
            if (temp <= 1) {
                nums[i] = temp;
                break;
            }
            else {
                nums[i] = 0;
                flag = 1;
                continue;
            }
        }
    }
}

vector<int> change(int num) {
    vector<int> result;
    int flag = 0;
    if (num < 0) {
        flag = 1;
        num = -num;
    }
    while (num != 0) {
        result.insert(result.begin(),num%2);
        num = num / 2;
    }
    if (flag == 1) {
        while (result.size() != 32) {
            result.insert(result.begin(),0);
        }
        result[0] = 1;
        add(result);
    }
    return result;
}

string vec_to_str(vector<int> nums) {
    string result = "";
    if (nums.size() == 0) return result;
    stringstream ss;
    for (int i = 0;i < nums.size();i++) {
        string temp = "";
        ss << nums[i];
        ss >> temp;
        ss.clear();
        result += temp;
    }
    return result;
}

long long str_to_int(string str) {
    long long result = 0;
    stringstream ss;
    ss << str;
    ss >> result;
    ss.clear();
    return result;
}

string change_decimal(string n) {
    vector<int> record;
    double temp = (double)str_to_int(n) / pow(10,n.length());
    cout << temp << endl;
    while (temp != 0&&record.size() < 32) {
        temp *= 2;
        if (temp >= 1) {
            temp -= 1;
            record.push_back(1);
        }
        else {
            record.push_back(0);
        }
    }
    if ((temp-0) < 1e-8) {
        return vec_to_str(record);
    }
    else {
        return "ERROR";
    }
}

string binaryRepresentation(string &n) {
    string a = "";
    string b = "";
    int index = -1;
    for (int i = 0;i < n.length();i++) {
        if (n[i] == '.') {
            index = i;
            break;
        }
    }
    a = n.substr(0,index);
    b = n.substr(index+1,n.length());
    a = vec_to_str(change(str_to_int(a)));
    b = change_decimal(b);
    if (b == "ERROR") {
        return b;
    }
    else if (a == "" && b == "") {
        return "0";
    }
    else if (a != "" && b == "") {
        return a;
    }
    else if (a == "" && b != ""){
        return "0." + b;
    }
    else {
        return a + "." + b;
    }
}

int main() {
    int a[5] = {1,2,3,4,5};
    vector<int> test(a,a+5);
    //cout << vec_to_str(change(-6)) << endl;
    string s = "4096.6435546875";
    //cout << change_decimal("6435546875") << endl;
    cout << binaryRepresentation(s) << endl;
    return 0;
}
