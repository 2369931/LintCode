#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> numberToString(int number) {
    vector<int> s;
    while (number) {
        int temp = number%10;
        s.insert(s.begin(), temp);
        number /= 10;
    }
    return s;
}

string convert(vector<int> vec, map<int, string> dict) {
    if (vec.size() == 1) {
        return dict[vec[0]];
    }
    else if (vec.size() == 2) {
        if (vec[0] <= 1 || vec[0] == 2 && vec[1] == 0) {
            return dict[vec[0]*10 + vec[1]];
        }
        else {
            if (vec[1] != 0)
                return dict[vec[0]*10] + " " + dict[vec[1]];
            else
                return dict[vec[0]*10];
        }
    }
    else {
        string temp = "";
        if (vec[0] == 0) {
            return temp;
        }
        else if (vec[1] == 0) {
            if (vec[2] != 0) {
                temp = dict[vec[2]];
            }
        }
        else {
            if (vec[1] <= 1 || vec[1] == 2 && vec[2] == 0) {
                temp = dict[vec[1]*10 + vec[2]];
            }
            else {
                if (vec[2] != 0)
                    temp = dict[vec[1]*10] + " " + dict[vec[2]];
                else
                    temp = dict[vec[1]*10];
            }
        }
        if (temp != "")
            return dict[vec[0]] + " hundred " + temp;
        else
            return dict[vec[0]] + " hundred";
    }
}

string convertWords(int number) {
    if (number == 0) {
        return "zero";
    }
    map<int, string> dict;
    dict[1] = "one";
    dict[2] = "two";
    dict[3] = "three";
    dict[4] = "four";
    dict[5] = "five";
    dict[6] = "six";
    dict[7] = "seven";
    dict[8] = "eight";
    dict[9] = "nine";
    dict[10] = "ten";
    dict[11] = "eleven";
    dict[12] = "twelve";
    dict[13] = "thirteen";
    dict[14] = "fourteen";
    dict[15] = "fifteen";
    dict[16] = "sixteen";
    dict[17] = "seventeen";
    dict[18] = "eighteen";
    dict[19] = "nineteen";
    dict[20] = "twenty";
    dict[30] = "thirty";
    dict[40] = "forty";
    dict[50] = "fifty";
    dict[60] = "sixty";
    dict[70] = "seventy";
    dict[80] = "eighty";
    dict[90] = "ninety";
    vector<int> vec = numberToString(number);
    /*for (int i = 0;i < vec.size();i ++) {
        cout << vec[i] << endl;
    }*/
    int n = vec.size();
    if (n <= 3) {
        return convert(vec, dict);
    }
    else if (n > 3 && n <= 6) {
        vector<int> first;
        vector<int> second;
        for (int i = n - 1;i > n - 4;i --) {
            first.insert(first.begin(),vec[i]);
        }
        for (int i = n - 4;i >= 0;i --) {
            second.insert(second.begin(),vec[i]);
        }
        string temp = convert(first, dict);
        if (temp != "")
            return convert(second, dict) + " thousand " + convert(first, dict);
        else
            return convert(second, dict) + " thousand";

    }
    else if (n > 6 && n <= 9) {
        vector<int> first;
        vector<int> second;
        vector<int> third;
        for (int i = n - 1;i > n - 4;i --) {
            first.insert(first.begin(),vec[i]);
        }
        for (int i = n - 4;i > n - 7;i --) {
            second.insert(second.begin(),vec[i]);
        }
        for (int i = n - 7;i >= 0;i --) {
            third.insert(third.begin(),vec[i]);
        }
        string temp = convert(second, dict) == ""?"":" "+convert(second, dict) + " thousand ";
        return convert(third, dict) + " million" + temp + convert(first, dict);
    }
    else {
        vector<int> first;
        vector<int> second;
        vector<int> third;
        vector<int> forth;
        for (int i = n - 1;i > n - 4;i --) {
            first.insert(first.begin(),vec[i]);
        }
        for (int i = n - 4;i > n - 7;i --) {
            second.insert(second.begin(),vec[i]);
        }
        for (int i = n - 7;i > n - 10;i --) {
            third.insert(third.begin(),vec[i]);
        }
        for (int i = n - 10;i >= 0;i --) {
            forth.insert(forth.begin(),vec[i]);
        }
        string temp = convert(third, dict) == ""?"":" "+convert(third, dict) + " million";
        string temp_1 = convert(second, dict) == ""?"":" "+convert(second, dict) + " thousand ";
        return convert(forth, dict) + " billion" +
        temp + temp_1 + convert(first, dict);
    }
}

int main() {
    cout << convertWords(1000000000) << endl;
    return 0;
}
