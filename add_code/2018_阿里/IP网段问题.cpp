#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

using namespace std;

int StringToInt(string s) {
    int result = 0;
    stringstream ss;
    ss << s;
    ss >> result;
    return result;
}

class ip {
public:
    int first;
    int second;
    int third;
    int forth;

    ip() {
        this->first = 0;
        this->second = 0;
        this->third = 0;
        this->forth = 0;
    }

    ip (string temp) {
        string record = "";
        int value[4] = {0};
        int j = 0;
        for (int i = 0;i < temp.length();i++) {
            if (temp[i] != '.') {
                record += temp[i];
            }
            else {
                value[j] = StringToInt(record);
                record = "";
                j ++;
            }
        }
        value[3] = StringToInt(record);
        this->first = value[0];
        this->second = value[1];
        this->third = value[2];
        this->forth = value[3];
    }

    ip(int a, int b ,int c, int d) {
        this->first = a;
        this->second = b;
        this->third = c;
        this->forth = d;
    }
};

int judge(ip p) {
    if (p.first > 255 || p.second > 255 || p.third > 255 || p.forth > 255) {
        return 0;
    }
    else {
        return 1;
    }
}

int change(int a) {
    int result = 0;
    for (int i = 0;i < a;i++) {
        result += pow(2,i);
    }
    return result;
}

int judge_2(ip p, ip q, int net) {
    int number = net/8;
    int mask[4] = {0};
    int i = 0;
    while (net > 0) {
        if (net >= 8) {
            mask[i] = change(8);
            net -= 8;
        }
        else {
            mask[i] = change(net);
            net -= net;
        }
        i++;
    }
    /*cout << mask[0] << " " << mask[1] << " " << mask[2] << " " << mask[3] << endl;
    cout << (p.first&mask[0]) << " " << (q.first&mask[0]) << " " << (p.second&mask[1]) << " "
     << (q.second&mask[1])  << " " << (p.third&mask[2]) << " " << (q.third&mask[2]) << " " << (p.forth&mask[3]) << " " << (q.forth&mask[3])<< endl;*/
    if (((p.first&mask[0]) == (q.first&mask[0])) && ((p.second&mask[1]) == (q.second&mask[1]))
        && ((p.third&mask[2]) == (q.third&mask[2])) && ((p.forth&mask[3]) == (q.forth&mask[3]))) {
            return 1;
        }
    else {
        return 0;
    }

}

int main() {
    string target;
    //cin >> target;
    target = "10.20.86.3";
    ip t(target);
    vector<string> test;
    string ss;
    //temp = "10.20.86.3/8";
    getline(cin, ss);
    string s = "";
    for (int i = 0;i < ss.length();i++) {
        if (ss[i] != ' ') {
            s += ss[i];
        }
        else {
            test.push_back(s);
            s = "";
        }
    }
    test.push_back(s);
    /*for (int j = 0;j < test.size();j++) {
        cout << test[j] << endl;
    }*/
    for (int j = 0;j < test.size();j++) {
        string temp = test[j];
        string value;
        string number;
        int index = 0;
        for (int i = 0;i < temp.length();i++) {
            if (temp[i] == '/') {
                index = i;
                break;
            }
        }
        value = temp.substr(0,index);
        //cout << value << endl;
        ip q(value);
        //cout << q.first << " " << q.second << " " << q.third << " " << q.forth << endl;
        number = temp.substr(index+1,temp.length() - index - 1);
        //cout << number << endl;
        if (judge_2(target,q,StringToInt(number)) == 1) {
            cout <<  value + '/' + number << endl;
        }
    }
    return 0;
}
