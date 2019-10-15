#include <iostream>
#include <string>

using namespace std;

string simplifyPath(string &path) {
    string result = "";
    int n = path.length();
    if (n == 0) {
        return result;
    }
    int start = 0;
    int i = 0;
    int flag_1 = 0;
    int flag_2 = 0;
    while (i < n-1) {
        if (path[i] == '/') {
            result += path[i];
            for (int j = i+1;j < n-1;) {
                if (path[j] == '/') {
                    flag_1 = 1;
                    j ++;
                    i = j - 1;
                }
                else if (path[j] == '.') {
                    flag_2 = 1;
                    j ++;
                    i = j - 1;
                }
                else {
                    if (flag_1 == 1 && flag_2 == 1) {
                        result = "/";
                    }
                    flag_1 = 0;
                    flag_2 = 0;
                    i = j;
                    i --;
                    break;
                }
            }
        }
        else {
            result += path[i];
        }
        i ++;
    }

    if (result.length() == 0 || (path[n-1] != '/'&& path[n-1] != '.')) {
        result += path[n-1];
    }
    return result;
}

string simplifyPath(string& path) {
     // Write your code here
     stack<string> st;
     string cur = "";
     path+="/";
     for(int i=0;i<path.length();i++)
     {
         if(path[i]=='/')
         {
             if(cur=="..")
             {
                 if(!st.empty())
                     st.pop();
             }
             else if(cur=="."){}
             else if(cur.length()>0)
             {
                 st.push(cur);
             }
             cur = "";
         }
         else
             cur+=path[i];
     }
     string ret = "";
     while(!st.empty())
     {
         ret = "/"+st.top()+ret;
         st.pop();
     }
     if(ret.length()==0)
         ret = "/";
     return ret;
}

int main() {
    string test = "///";
    cout << simplifyPath(test) << endl;
    return 0;
}
