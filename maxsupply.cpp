/*
给出一个数字（10,000～100,000,000），把这个数字拆分成4段，怎样使得4段的乘积最小。比如12345拆分成1*2*3*45=270, 10000=1*00*0*0=0。
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits.h>
using namespace std;

#define MAXLEN 30
int dp[MAXLEN][MAXLEN];
int num[MAXLEN][MAXLEN];

//假设dp[i][j]表示分成i段，且字符串指针移动到第j位时的最小乘积。  则显然i<=j.
//num[i][j]是数字中从第i个数字到第j个数字组成的数字
//dp[i][j]=min{dp[i-1][k] *num[k+1][j]}, i-1<=k<j, 因为digits从0开始，所以代码里些为i-2
int solve_dp(int *digits, int len, int m, int (*dp)[MAXLEN], int (*num)[MAXLEN]);

//递归解决
int solve_recursion(int *digits, int len, int m);

int main(){
	int number, m;
	char buf[MAXLEN];
	int digits[MAXLEN];
	int len;
	scanf("%d %d", &number, &m);
	len=sprintf(buf, "%d", number);//获得输入数字的每一位
	for(int i=0; i<len; i++)
		digits[i]=buf[i]-'0';
//	cout<<strlen(buf)<<endl;

	for(int i=0; i<len; i++){
		int temp=0;
		for(int j=0; j<len; j++){
			if(i>j){
				num[i][j]=1;cout<<num[i][j]<<" ";
				continue;
			}
			temp=temp*10+digits[j];
			num[i][j]=temp; cout<<num[i][j]<<" ";
		}
		cout<<endl;
			
	}

	int result=solve_dp(digits, len, m, dp, num);
	cout<<"dp: "<<result<<endl;

	result=solve_recursion(digits, len, m);
	cout<<"recursion: "<<result<<endl;


}
//假设dp[i][j]表示分成i段，且字符串指针移动到第j位时的最小乘积。  则显然i<=j.
//num[i][j]是数字中从第i个数字到第j个数字组成的数字
//dp[i][j]=min{dp[i-1][k] *num[k+1][j]}, i-1<=k<j, 因为digits从0开始，所以代码里些为i-2
int solve_dp(int *digits, int len, int m, int (*dp)[MAXLEN], int (*num)[MAXLEN]){
	for(int i=0; i<len; i++){
		dp[1][i]=num[0][i];
	}
	
	for(int i=2; i<=m; i++){
		for(int j=i-1; j<len; j++){
			int min=INT_MAX;
			for(int k=i-2; k<j; k++){
				int temp=dp[i-1][k]	* num[k+1][j];
				if(temp < min)
					min=temp;
			}
			dp[i][j]=min;
		}
	}
	
	return dp[m][len-1];
}


int solve_recursion(int *digits, int len, int m){
	if(digits == NULL || len<m)
		return -1;
	if(m == 1){
		int res=0;
		for(int i=0; i<len; i++)
			res=res*10+digits[i];
		return res;
	}
		
	if(len == m)
		return solve_recursion(digits, len-1, m-1) * digits[len-1];
	int min=INT_MAX;
	int last=0, temp=1, base=1;
	for(int i=len-1; i>=m-1; i--){
		last += base*digits[i];
		base *= 10;
		temp=solve_recursion(digits, i, m-1) * last;
		if(temp < min)
			min=temp;
	}
	return min;

}
