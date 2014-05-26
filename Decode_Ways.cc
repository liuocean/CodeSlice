/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.
*/

#include<iostream>
#include<unordered_map>


using namespace std;

class Solution{
public:
	int numDecodings_recursive(string s);
	int numDecodings_recursive_memo(unordered_map<string, int>&hashmap, string s);
	int numDecodings_dp(string s);
};

int Solution::numDecodings_recursive(string s){
	if(s.length() == 0)
		return 1;
	int num=numDecodings_recursive(s.substr(1));
	if(s.length() >=2){
		string temp=s.substr(0,2);
		if(temp.compare("26") <= 0)
   			num+=numDecodings_recursive(s.substr(2));
	}
	return num;
}

//递归+备忘录
int Solution::numDecodings_recursive_memo(unordered_map<string, int>&hashmap, string s){
	if(s.length() == 0)
		return 1;
	int num=0;
	if(hashmap.find(s.substr(1)) == hashmap.end())
		num=numDecodings_recursive_memo(hashmap, s.substr(1));
	else num=hashmap[s.substr(1)];
	
	if(s.length() >=2){
		string temp=s.substr(0,2);
		if(temp.compare("26") <= 0){
			if(hashmap.find(s.substr(2)) == hashmap.end())
				num += numDecodings_recursive_memo(hashmap, s.substr(2));
			else num += hashmap[s.substr(2)];
			
		}
	}

	hashmap[s]=num;
	return num;
}

int main(){
	string s="128";

	Solution solution;
	int num=solution.numDecodings_recursive(s);
	cout<<num<<endl;
	
	unordered_map<string, int>hashmap;
	num=solution.numDecodings_recursive_memo(hashmap, s);
	cout<<num<<endl;

	return 0;

	
}
