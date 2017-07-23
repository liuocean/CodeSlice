/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/

#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:

    bool canJump(int A[], int n) {
		return find(A, 0, n);
	}

	bool find(int A[], int depth, int n){
		if(n <= 0)
			return false;

		if(depth == n-1)
			return true;

		int max=A[depth];
		if(max == 0)//死循环
			return false;

		bool flag=false;
		for(int i=1; i<=max; i++){
			flag=find(A, depth+i, n);
			if(flag)
				break;
		}

		return flag;
	}

	//递归超时，考虑用一个bool数组b，当A[i]不为0， 将b[i+1]到b[i+A[i]]的元素都设为true, 这样一次遍历后，如果A[n-1] 为true,则能达到
	bool canJump_1(int A[], int n){
		if(n <= 0)
			return false;
		bool B[n];
		memset(B, 0, sizeof(B));
		B[0]=true;

		for(int i=0; i<n;  ){
			while(!B[i])
				i++;
			if(A[i] == 0){
				int j=i+1;
				while(j<n && !B[j])
					++j;
				if(j == n)
					return false;
				else i=j;
			}
			else{
				for(int j=A[i]; j >=1; --j){
					if(i+j == n-1)
						return true;

					B[i+j]=true;
				}	
			}

			i++;
		}

		return false;
	}
};	


int main(){
	int A[]={3, 2, 1, 0, 4};
	//int A[]={2, 3, 1, 1, 4};

	Solution solution;
//	bool flag=solution.canJump(A, sizeof(A)/sizeof(int));
	bool flag=solution.canJump_1(A, sizeof(A)/sizeof(int));


	if(flag)
		cout<<"hah"<<endl;
	else cout<<"Oops"<<endl;
	
	return 0;
}
