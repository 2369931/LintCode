#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> split(string str,string separator){
	vector<string> result;
	int cutAt;
	while((cutAt = str.find_first_of(separator))!=str.npos){
		if(cutAt>0){
			result.push_back(str.substr(0,cutAt));
		}
		str=str.substr(cutAt+1);
	}
	if(str.length()>0){
		result.push_back(str);
	}
	return result;
}

vector<string> missingString(string &str1, string &str2) {
    vector<string> res;
    if (str1 == "" && str2 == "") {
        return res;
    }
    if (str1 == "" && str2 != "") {
        return split(str2," ");
    }
    if (str1 != "" && str2 == "") {
        return split(str1," ");
    }
    int n = str1.length();
    int m = str2.length();
    if (n < m) {
        string temp = str1;
        str1 = str2;
        str2 = temp;
    }
    vector<string> str_1 = split(str1," ");
    vector<string> str_2 = split(str2," ");
    for (int i = 0;i < str_1.size();i++) {
        vector<string>::iterator it = find(str_2.begin(), str_2.end(), str_1[i]);
        if (it == str_2.end()) {
            res.push_back(str_1[i]);
        }
    }
    return res;
}

int main() {
    string str2 = "this is lego";
    string str1 = "lego";
    vector<string> res = missingString(str1, str2);
    for (int i = 0;i < res.size();i++) {
        cout << res[i] << endl;
    }
    return 0;
}
