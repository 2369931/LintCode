#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n)
 {
	 string res = "1";
	 while(--n)
	 {
		 int count = 1;
		 string temp = "";
		 for(int i = 1;i < res.size();i++)
		 {
			 if(res[i] == res[i-1])
			 {
				 count++;
			 }
			 else
			 {
				 temp += to_string(count)+res[i-1];
				 count = 1;
			 }
		 }
		 temp += to_string(count) + res.back();
		 res = temp;
	 }
	 return res;
 }

