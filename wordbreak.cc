#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// res[i]保存从0到i能否匹配
class Solution{
public:
	bool wordBreak(string s, unordered_set<string> &dict){
		if(s.length() == 0)
			return true;
		vector<bool>res(s.length()+1, false);
		res[0]=true;
		for(int i=1; i<=s.length(); i++){
			for(int j=0; j<i; j++){
				if(res[j] && dict.find(s.substr(j, i-j)) != dict.end() ){
						res[i]=true; 
						continue;
				}
			}
		}
		return res[s.length()];
	}
};

class Solution1{
	
public:
	bool wordBreak(string s, unordered_set<string> &dict){
		if(s.length() == 0)
			return true;
		vector<vector<bool> >res(s.length()+1 , vector<bool>(s.length()+1, false);
		
		for(int i=1; i<=s.length(); i++){
			for(int j=0; j<i; j++){
				if(res[j] && dict.find(s.substr(j, i-j)) != dict.end() ){
						res[i]=true; 
				}
			}
		}
	}
};



int main(){
	string str="leetcode";

	unordered_set<string>dict;
	dict.insert("lee");
	dict.insert("leet");
	dict.insert("cdo");
	dict.insert("code");

	Solution solution;
	
	bool flag=solution.wordBreak(str, dict);
	if(flag)
		cout<<"true"<<endl;
	else cout<<"false"<<endl;
	return 0;

}
