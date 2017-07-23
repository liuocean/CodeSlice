#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	//DFS +backtracking,������ȣ����˷�����ʱ
	void wordBreak2(string s, unordered_set<string> &dict, string &result, vector<string> &res); 
    vector<string> wordBreak(string s, unordered_set<string> &dict);


	//����д��Ȼ�ǳ�ʱ�ģ���Ҫ��Ϊȱ�ټ�֦��������Ϊdp��i����ʾ����0��i�ܷ񹹳ɣ���ʹ�ܴӺ���ǰ��֦�������ˣ�
	//������Ҫ�������򣬴Ӻ���ǰ�ƣ�dp��i����ʾi��ĩβ�ܷ񹹳ɣ�������0��ʼ����Ӧ�ü�֦
	//�����ѵ�ʱ������ұߵĴ����ܱ���ʾ����ô�Ϳ��Բ������ݹ飬�Ӷ������˹���Ĳ��ܱ�ʾ�����ֵĵݹ顣
	//������Ҫ�ľ���������iʱ����һ��i+1��n-1�Ƿ���Ա��ʵ��ʾ��������ܱ���ʾ��ֱ�ӷ��ء�
	//��Ҫ���������dp����ʾ��i��n-1�Ƿ��ܱ��ʵ��еĴʱ�ʾ��
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

//ʹ��һά��������־
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

//����д��Ȼ�ǳ�ʱ�ģ���Ҫ��Ϊȱ�ټ�֦��������Ϊdp��i����ʾ����0��i�ܷ񹹳ɣ���ʹ�Ӻ���ǰ��֦�������ˣ�
//������Ҫ�������򣬴Ӻ���ǰ�ƣ�dp��i����ʾi��ĩβ�ܷ񹹳ɣ�������0��ʼ����Ӧ�ü�֦
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

