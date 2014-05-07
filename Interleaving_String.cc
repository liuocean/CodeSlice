/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

*/

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Solution{
public:
	bool isInterleave(string s1, string s2, string s3){// 递归方法，超时
		if(s1.length() + s2.length() != s3.length())
			return false;
		
		if(s3.length() == 0)
			return true; //这里显然为true,前面已经判断过，长度相等，所以s1 s2也为空，不判断后面substr出现异常

		if(s1[0] == s2[0] && s2[0] == s3[0] )//三个字符串首字符相等，这时无法判断s3的首字符来自s1还是s2,所以两种情况都要判断
			return isInterleave(s1.substr(1), s2, s3.substr(1)) || isInterleave(s1, s2.substr(1), s3.substr(1));
		
		else if(s1[0] == s3[0])
			return isInterleave(s1.substr(1), s2, s3.substr(1));
		
		else if(s2[0] == s3[0])
			return isInterleave(s1, s2.substr(1), s3.substr(1));
		
		else return false; //s1，s2的首字符都与s3不等，返回false
		
	}

	//动态规划算法, dp[i][j] 表示s1的前i个字符与s2的前j个字符，能够表示s3的前i+j个字符

	bool isInterleave_dp(string s1, string s2, string s3){
		if(s1.length() + s2.length() != s3.length())
			return false;
		
		if(s3.length() == 0)
			return true; //这里显然为true,前面已经判断过，长度相等，所以s1 s2也为空，不判断后面substr出现异常

		int dp[s1.length() + 1][s2.length() + 1];
		memset(dp, 0, sizeof(dp)); //擦类，坑跌啊，memset 第三个参数是dp所占字节数，而不是int 个数，切记
		dp[0][0]=1;
		
		for(int j=1; j<=s2.length(); j++)
			if(dp[0][j-1]==1 && s2[j-1]==s3[j-1]) //初始化注意，这里不考虑s1中的字符，s2的前j个字符能表示s3，表示前j-1个字符也能表示s3,且第j个字符与s3相同，下行不考虑s2，类似
				dp[0][j]=1;
		for(int i=1; i<=s1.length(); i++)
			if(dp[i-1][0]==1 && s1[i-1]==s3[i-1])
				dp[i][0]=1;

		for(int i=1; i<=s1.length(); i++){
			for(int j=1; j<=s2.length(); j++){
				if((dp[i-1][j]==1 && s1[i-1]==s3[i+j-1]) || (dp[i][j-1]==1 && s2[j-1]==s3[i+j-1])) //这里又迷糊了，i+j-1而不是i+j-2，因为此时算dp[i][j]
					dp[i][j]=1;
			}
		}

		for(int i=0; i<=s1.length(); i++){
			for(int j=0; j<=s2.length(); j++)
				cout<<dp[i][j]<<" ";
			cout<<endl;
		}

		return dp[s1.length()][s2.length()] == 1;
	}

};

int main(){
	string s1="aabcc";
	string s2="dbbca";
	string s3="aadbbcbcac";

	Solution solution;
	bool res=solution.isInterleave(s1, s2, s3);
	if(res)
		cout<<"yeah,hah"<<endl;
	else cout<<"oops"<<endl;

	res=solution.isInterleave_dp(s1, s2, s3);
	if(res)
		cout<<"yeah,hah"<<endl;
	else cout<<"oops"<<endl;

	return 0;
}
