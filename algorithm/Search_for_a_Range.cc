/*
Search for a Range 
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int leftBorder(int A[], int n, int target);
    int rightBorder(int A[], int n, int target);
    vector<int> searchRange(int A[], int n, int target);
    
};

int Solution::leftBorder(int A[], int n, int target){
    if(!A || n<=0)
        return -1;
    int low=0, high=n-1;
    while(low < high){
       int mid=low + ((high -low) >> 1); ////一定注意移位运算符的优先级低于算术运算符
       if(A[mid]==target) 
            if(mid==0 || A[mid-1]!=target)
              return mid;
            else high=mid-1;
        else if(A[mid] > target)
            high=mid-1;
        else low=mid+1;
    }
    
    return (A[low] == target) ?low : -1;
}

int Solution::rightBorder(int A[], int n, int target){
    if(!A || n<=0)
        return -1;
    int low=0, high=n-1;
    while(low < high){
       int mid=low + ((high -low) >> 1);  //一定注意移位运算符的优先级低于算术运算符
       if(A[mid]==target) 
            if(mid==high || A[mid+1]!=target)
              return mid;
            else low=mid+1;
        else if(A[mid] > target)
            high=mid-1;
        else low=mid+1;
    }
    
    return (A[low] == target) ?low : -1;
}

vector<int> Solution::searchRange(int A[], int n, int target){
    int left=leftBorder(A, n, target);
    int right=rightBorder(A, n, target);
    vector<int> res;
    res.push_back(left);
    res.push_back(right);
    return res;
}


int main(){
	int A[]={5, 7, 7, 8, 8, 9};
	Solution solution;
	vector<int>res;
	res=solution.searchRange(A, sizeof(A)/sizeof(int), 8);
	cout<<res[0]<<" "<<res[1]<<endl;
	return 0;
}