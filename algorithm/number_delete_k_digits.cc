/*
对于一个n位正整数a,去掉其中任意k(k<=n)个数字后，剩下的数字按原次序排列可以组成一个新的正整数。设计一个删除算法，使得剩下的数字组成的正整数最小。
例如，a=13243221，k=5，输出：121
*/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char * delete_k_digits(char *str, int k);
char * delete_k_digits_v(char *str, int k);


int main(){
	char str[]="342";
	int k=1;
	char *p=delete_k_digits(str, k);
	printf("%s\n", p);

	char strv[]="1335";
	k=1;
	char *q=delete_k_digits_v(strv, k);
	printf("%s\n", q);
}


char *delete_k_digits(char *str, int k){
	int len=strlen(str);
	if(len <= k)
		return NULL;
	int i;
	while(k>0){
		i=0;
		while(i<len-1 && str[i] <= str[i+1]) //注意，这里必须算<= ,考虑1335 k=1
			i++;
		for(int j=i; j<len; j++)
			str[j]=str[j+1];

		k--;
		len--;
	}
	str[len]='\0';
    return str;
}

char *delete_k_digits_v(char *str, int k){
	int len=strlen(str);
	if(len <= k)
		return NULL;
	int i=0;
	while(k > 0){
		if(str[i] <= str[i+1]){
			while(i<len-1 && str[i] <= str[i+1])
				i++;
		}
        else{
			while(i>0 && str[i] <str[i-1])
				i--;
		}
	
	    for(int j=i; j<len-1; j++)
			str[j]=str[j+1];

		k--;
		len--;
	}

	str[len]='\0';
	return str;
}
