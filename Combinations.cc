/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/


#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<cstdlib>


using namespace std;

class Solution {
public:
    void selectk(int n, int k, int start, vector<int>&temp, vector<vector<int> >&res){  //注意参数选择，start 防止重复选择
        if(k == 0){
            res.push_back(temp);
            return;
        }
        for(int i=start; i<=n; i++){
            temp.push_back(i);
            selectk(n, k-1, i+1, temp, res);
            temp.pop_back();
        }
    }

   vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >res;
        vector<int>temp;
        selectk(n, k, 1, temp,  res);
        return res;
    }

	//非递归算法选择K个元素,元素从1到N
	vector<vector<int> >combine_nonrecursion(int n, int k){
		vector<vector<int> >res;
		vector<int>temp(k);//vector 大小为K
		int i=0;
		temp[i]=0;
		while(i>=0){
			temp[i]++;
			if(temp[i] > n){
				temp[i]=0;
				i--;
			}else{
				if(i == k-1){//已经选择了k个元素
					res.push_back(temp);
				}else{
					temp[i+1]=temp[i];//保证后面元素比下面元素大，防止重复，这里直接赋值，因为while开头会增加
					i++;
				}
			}
		}
		return res;
	}

//非递归用stack实现，原理同上
	vector<stack<int> >combine_nonrecursion_stack(int n, int k){
		vector<stack<int> >res;
		//vector<int>temp;
		stack<int>st;
		int i=0;
		st.push(0);
		while(!st.empty()){
			int t=st.top();
			st.pop();

			if(t < n){
				t++;
				st.push(t);

				if(st.size() == k){
					res.push_back(st);
				}else{
					st.push(t);
				}
			}
		}
		return res;
	}
	
};


int main(){
	vector<vector<int> >res;
	int n=4, k=2;
	Solution solution;
	res=solution.combine(n, k);
	
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<k; j++)
			cout<<res[i][j]<<' ';	
		cout<<endl;
	}
cout<<"*********************************&&&&&&&&&&&&&&&&&&&&&&****************************"<<endl;
	res=solution.combine_nonrecursion(n, k);
	
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<k; j++)
			cout<<res[i][j]<<' ';	
		cout<<endl;
	}

cout<<"*********************************&&&&&&&&&&&&&&&&&&&&&&****************************"<<endl;
	vector<stack<int> >stres;
	stres=solution.combine_nonrecursion_stack(n, k);
	
	for(int i=0; i<stres.size(); i++){
		while(!stres[i].empty()){
			cout<<stres[i].top()<<" ";
			stres[i].pop();
		}
		cout<<endl;
	}

}
