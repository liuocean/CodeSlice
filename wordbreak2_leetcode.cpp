#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	//DFS +backtracking,深度优先，但此方法超时
	void wordBreak2(string s, unordered_set<string> &dict, string &result, vector<string> &res); 
    vector<string> wordBreak(string s, unordered_set<string> &dict);


	//这样写依然是超时的，主要因为缺少剪枝，但是因为dp【i】表示的是0到i能否构成，即使能从后往前剪枝，逆序了，
	//所以需要换个方向，从后往前推，dp【i】表示i到末尾能否构成，这样从0开始可以应用剪枝
	//当深搜的时候，如果右边的串不能被表示，那么就可以不继续递归，从而避免了过多的不能表示而出现的递归。
	//这里需要的就是搜索到i时，看一下i+1到n-1是否可以被词典表示，如果不能被表示就直接返回。
	//需要从右往左的dp。表示从i到n-1是否能被词典中的词表示。
	vector<string> solve_dp1(string s, unordered_set<string> &dict);
	void dfs1(int start, string s, unordered_set<string> &dict, vector<bool> dp, string &result, vector<string> &res);
	
};

void Solution::wordBreak2(string s, unordered_set<string> &dict, string &result, vector<string> &res){
	if(s.size() == 0){
		res.push_back(result);
		return ;
	}

	for(int i=1; i<=s.size(); i++){
		string temp=s.substr(0, i);
		unordered_set<string>::iterator it=dict.find(temp);
		if(it != dict.end()){
			string t=result + " " + temp;
			wordBreak2(s.substr(i), dict, t, res);
		}
	}
}

vector<string> Solution::wordBreak(string s, unordered_set<string> &dict) {
	vector<string> res;
	string result="";
	wordBreak2(s, dict, result, res);
	return res;
}

//使用一维数组做标志
vector<string> Solution::solve_dp1(string s, unordered_set<string> &dict){
		vector<string>res;	
		if(s.length() == 0)
			return res;
		vector<bool>dp(s.length()+1, false);
		dp[0]=true;
		for(int i=1; i<=s.length(); i++){
			for(int j=0; j<i; j++){
				if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end() ){
					dp[i]=true; 
					continue;
				}
			}
		}
		
		string result;
		dfs1(1, s, dict, dp,  result, res);
		return res;
}

//这样写依然是超时的，主要因为缺少剪枝，但是因为dp【i】表示的是0到i能否构成，即使从后往前剪枝，逆序了，
//所以需要换个方向，从后往前推，dp【i】表示i到末尾能否构成，这样从0开始可以应用剪枝
void Solution::dfs1(int start, string s, unordered_set<string> &dict, vector<bool> dp, string &result, vector<string> &res){
	if(start > s.size())
		return;
	for(int i=start; i<=s.size(); ++i){
		string temp=s.substr(start-1, i-start+1);
		if(dp[i] && (dict.find(temp) != dict.end())){
			if(i == s.size()){
				res.push_back(result);
				continue;
			}
			dfs1(i+1, s, dict, dp, result + " " + temp, res);
		}
	}
}


int main(){
	string s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	unordered_set<string> dict;
	dict.insert("aa");
	dict.insert("a");
	//dict.insert("and");
	//dict.insert("sand");
	//dict.insert("dog");

	vector<string> res;
	Solution solution;

	//res=solution.wordBreak(s, dict);
	res=solution.solve_dp1(s, dict);

	for(vector<string>::iterator it=res.begin(); it!=res.end(); it++)
		cout<<*it <<endl;

	system("pause");
	return 0;
}

