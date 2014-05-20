/*
Longest Valid Parentheses
Given a string containing just the characters ‘(‘ and ‘)’, find the length of the longest valid (well-formed) parentheses substring.
For “(()”, the longest valid parentheses substring is “()”, which has length = 2.
Another example is “)()())”, where the longest valid parentheses substring is “()()”, which has length = 4

*/

#include<iostream>
#include<stack>

#include<cstring>

using namespace std;

class Solution{
public:
	int longestValidParentheses_dp(string s);
	int longestValidParentheses(string s);
	int longestValidParentheses_1(string s);
};

//dp[i]表示从i到len-1的匹配长度
int Solution::longestValidParentheses_dp(string s){
	int length=s.size();
	int dp[length + 1];
	memset(dp, 0, sizeof(dp));
	dp[length -1]=0;
	int max=0;

	for(int i=length-2; i>=0; --i){
		if(s[i] == '('){
			int k=i+1+dp[i+1];
			if(k < length && s[k]==')')
				dp[i]=dp[i+1]+2;
			if(k+1 < length)
				dp[i]+=dp[k+1];

			if(dp[i] > max)
				max=dp[i];
		}
	}

	return max;
}

int Solution::longestValidParentheses(string s){
	stack<int>st;
	int start=0; //start 标记一个新组的开始位置，也可以标记一个数组的结束位置
	int max=0;

	for(int i=0; i<s.size(); i++){
		if(s[i]=='(')
			st.push('(');
		else{
			if(st.empty())
				start=i+1; //遇到不匹配的，从下一个开始新组
			else{
				st.pop(); //之所以能直接出栈，是因为栈里只有左括号( 
				int temp=st.empty() ? (i-start+1) : (i-st.top());  //加1 和 不加
				if(temp > max)
					max=temp;
			}
		}
	}

	return max;
}


int Solution::longestValidParentheses_1(string s){
	stack<int>st;
	int last=-1; //标记一个数组的结束位置
	int max=0;

	for(int i=0; i<s.size(); i++){
		if(s[i]=='(')
			st.push('(');
		else{
			if(st.empty())
				last=i; //遇到不匹配的，标记上一个数组结束位置
			else{
				st.pop(); //之所以能直接出栈，是因为栈里只有左括号( 
				int temp=st.empty() ? (i-last) : (i-st.top()); 
				if(temp > max)
					max=temp;
			}
		}
	}

	return max;
}

int main(){
	string s=")()()()))))";
	Solution solution;
	int len=solution.longestValidParentheses_dp(s);
	cout<<len<<endl;

	len=solution.longestValidParentheses(s);
	cout<<len<<endl;

	len=solution.longestValidParentheses_1(s);
	cout<<len<<endl;
	
	return 0;
}
