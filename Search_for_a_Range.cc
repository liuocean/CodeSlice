#include<iostream>

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
       int mid=low + (high -low) >> 1; 
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
       int mid=low + (high -low) >> 1; 
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