#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

const int BIT_INDEX_FILE=15;
const int BIT_INDEX_OFFSET=17;
const unsigned int FILE_RNAGE=1<<BIT_INDEX_FILE;
const unsigned int FILE_RANGE_FLOOR=0;
const unsigned int OFFSET_RANGE_CEIL =1<<BIT_INDEX_OFFSET;
const int MAX_LINE=100000000;

const int MAX_NUM_PER_LINE=500;

long totalnum=0;

int main(){

	unsigned int lastfile= FILE_RANGE_FLOOR;
	unsigned int file=0;
	FILE *fp;


	fp=fopen("/home/ly/sata/lvm/reverse-sample.txt", "w");
	if(!fp){
		cout<<"error open file"<<endl;
		return -1;
	}

	int i=0;
	while(i++ < MAX_LINE && file<FILE_RNAGE){
		//srand((unsigned)time(0));
		unsigned int feature;
		
		file=lastfile + 1 + rand()%2;
		if(file >= FILE_RNAGE) break;
		lastfile=file;
cout<<file<<endl;
 		//int file_contain_feature=rand()%10;
		int file_contain_feature= rand()%OFFSET_RANGE_CEIL;
		int origin=file_contain_feature;
		//i+=file_contain_feature;
		
		unsigned int lastoffset=0, offset=0;  //偏移量起始地址
		while(file_contain_feature-- > 0 && offset<OFFSET_RANGE_CEIL){  //生成一行对应的偏移地址
			i++;

			offset=lastoffset + 1 +rand()%200;
			lastoffset=offset;
		

			feature=(file<<BIT_INDEX_FILE)+offset;
			int num=rand()%MAX_NUM_PER_LINE + 1; //not be 0
totalnum+=num;
//cout<<"line="<<i<<" feature="<<std::hex<<feature<<" num="<<std::dec<<num<<endl;
			fprintf(fp, "%08x ", feature);
			while(num-- > 0){
				fprintf(fp, "%d %d ", rand()%RAND_MAX, rand()%10+1);
			}
			fprintf(fp, "\n");		
		}

	}
	fclose(fp);
	
	cout<<"totalline"<<i<<endl;
cout<<"totalnum"<<totalnum<<endl;


cin>>file;

//生成查询样本
	string featureIndex="/home/ly/workspace/feature_sample/";
	char buf[10];	
	for(int i=0;i<1000;i++){
		sprintf(buf, "%d", i);
		string filename=featureIndex + "feature_sample" + string(buf) + ".txt";


		fp=fopen(filename.c_str(), "w");
		if(!fp){
			cout<<"error open file"<<endl;
			return -1;
		}
		int num=rand()%300;
		int total=0;

		fprintf(fp, "%s %d ", "name", num);
		vector<unsigned int>fVec;
		unsigned int offset,feature;
		while(num-- > 0){
			file=rand()%FILE_RNAGE;	
			int num_in_file=rand()%10;
			total+=num_in_file;

			while(num_in_file-- > 0){
				offset=rand()%OFFSET_RANGE_CEIL;  //偏移量
				feature=(file<<BIT_INDEX_FILE)+offset;
				fVec.push_back(feature);
			}
		}
		sort(fVec.begin(), fVec.end());
cout<<total<<endl;
		for(vector<unsigned int>::iterator it=fVec.begin(); it!=fVec.end(); it++)
			fprintf(fp, "%x ", *it);
		fclose(fp);
	}

}



