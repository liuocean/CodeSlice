/*

原题

给定一个数组，我们可以找到两个不相交的、并且是连续的子数组A和B，A中的数字和为sum(A), B中的元素和为sum(B)。找到这样的A和B，满足sum(A) - sum(B)的绝对值是最大的。例如：[2, -1 -2, 1, -4, 2, 8]划分为A=[-1, -2, 1, -4], B=[2, 8]， 最大的值为16

分析

如果没有比较丰富的经验，这个题目咋一看，有一种不明觉厉的感觉。但只要逐层分析，就可以看到，其实只要分析两层就可以了。首先我们来看看题目有哪些要点：

子数组是不相交的
子数组是连续的，这个有点多余，但还是强调一下得好
然后题目的要求是，差的绝对值最大。那我们自然而然能够想到：找到的两个不相交的子数组，一个值要很小，一个值要很大。这样才能够保证差的绝对值最大。那如何找到这样的数组呢？我们从不相交的这个条件入手。看题目中例子：

0	1	2	3	4	5	6
2	-1	-2	1	4	2	8
看上面的表格，如果两个子数组不想交，我们有六个位置，作为划分的备选，0和1之间、1和2之间、2和3之间，直到5和6之间。这六个位置，都可以将数组划分为两部分。我们设定，数组长度为n，i将数据划分为两部分分别为 [0,i-1]和[i,n-1]。都是两边包含的集合。i是从1到n-1的。

对于任意的i，我们得到了两部分[0, i-1]和[i, n-1]。接下来，就是在这两部分中，找到一个和最小的子数组A，以及和最大的子数组B。那么A-B的绝对值，就是i这个划分下，满足条件的两个数组的差的最大值。对于，所有的i而言，这个绝对值最大时的A和B就是我们要找到的。


*/

#include <iostream>
#include <cstdlib>
using namespace std;

const int NUM=100;

//从0开始到数组当前元素之前子数组最大值
int max_sub_array(int array[], int len, int maxarray[]){
	int sum=array[0];
	int max=sum;

	for(int i=1; i<len; i++){
		maxarray[i]=max; //注意，这里max[i]表示从0到 i-1中子数组的最大值，不包括a[i]
		if(sum < 0)
			sum=array[i];
		else sum+=array[i];

		if(sum > max)
			max=sum;
	}
	
	for(int i=0; i<len; i++)
		cout<<maxarray[i]<<" ";
	cout<<endl;
}

//从len-1 开始到0，数组每个元素的最小子数组
int min_sub_array(int array[], int len, int minarray[]){
	int min=array[len-1];
	int sum=min;
	minarray[len-1]=min;

	for(int i=len-2; i>=0; i--){
		if(sum >= 0)
			sum=array[i];
		else sum+=array[i];

		if(sum < min)
			min=sum;
		
		minarray[i]=min; //minarray[i] 包含从0到len-1中子数组的最小子段和
	}

	for(int i=0; i<len; i++ )
		cout<<minarray[i]<<" ";
	cout<<endl;
}



int main(){
	int array[]={2, -1, -2, 1, -4, 2, 8};
	int max[NUM];
	int min[NUM];

	max_sub_array(array, sizeof(array)/sizeof(int), max);
	
	min_sub_array(array, sizeof(array)/sizeof(int), min);

	//求最大绝对值

	int maxabs=0,temp;
	for(int i=1; i<sizeof(array)/sizeof(int); i++){
		temp=abs(max[i]-min[i]);
		if(temp > maxabs)
			maxabs=temp;
	}
	cout<<maxabs<<endl;
	

	return 0;
}



