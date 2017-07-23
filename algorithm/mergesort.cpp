#include<iostream>
using namespace std;

//merge begin ~ mid,  mid+1 ~ end
void merge(int *unsorted, int *sorted, int begin, int mid ,int end){
cout<<"merge"<<begin << " "<<mid<<" "<<end <<endl;
	int i=mid;
	int j=end;
	int k=end;
	while(i>=begin && j>mid){
		if(unsorted[i] >= unsorted[j]){
			sorted[k--]=unsorted[i--];
		}
		else sorted[k--]=unsorted[j--];
		
	}
	while(i>=begin)
		sorted[k--]=unsorted[i--];
	while(j>mid)
		sorted[k--]=unsorted[j--];
	for(int i=begin;i<=end; i++)
		unsorted[i]=sorted[i];
}

void mergesort(int *unsorted,int *sorted, int begin, int end){
	if(begin >= end)
		return ;
	cout<<begin <<end <<endl;
	int mid=((end - begin)>>1) +begin; //int mid=begin+(end - begin)>>1; 
	mergesort(unsorted, sorted, begin, mid);
	mergesort(unsorted, sorted, mid+1, end);
	merge(unsorted, sorted, begin, mid, end);	
}


int main(){
	int unsorted[]={2,3,1,4,7,3};
	int sorted[10];
	cout<<sizeof(unsorted)/sizeof(int)-1<<endl;
	mergesort(unsorted, sorted, 0, sizeof(unsorted)/sizeof(int)-1);
	for(int i=0; i<sizeof(unsorted)/sizeof(int); i++)
		cout<<sorted[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
	}