/*
	 不定长二维数组，求所有组合
*/
#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

typedef struct	Row{
	int len;
	int *data;
}Row;

typedef struct Matrix{
	int row_total;
	Row *row;
}Matrix;

void combination(int row, Matrix *matrix, vector<int>&temp, vector<vector<int> > &vec){
	if(row == matrix->row_total ){
		vec.push_back(temp);	
		return;
	}	
	
	for(int i=0; i<matrix->row[row].len; i++){
		temp.push_back(matrix->row[row].data[i]);
		combination(row + 1, matrix, temp, vec);
		temp.pop_back();
	}
}

int main(){
	int ROW = 3;
	Matrix *matrix;
	matrix = (Matrix *)malloc(sizeof(Matrix));
	matrix->row = (Row *)malloc(ROW * sizeof(Row));
	matrix->row_total = ROW;

	for(int i=0; i< ROW; i++){
		matrix->row[i].data = (int *)malloc((i+1) *sizeof(int));
		matrix->row[i].len = i + 1;
		for(int j=0; j<matrix->row[i].len; j++)
			matrix->row[i].data[j] = i+j;
	}
	
	for(int i=0; i<matrix->row_total; i++)
	{
		for(int j=0; j < matrix->row[i].len; j++)
			cout<<matrix->row[i].data[j]<<" ";
		cout<<endl;
	}

	vector<int>temp;
	vector<vector<int> >vec;
	combination(0, matrix, temp, vec);

	for(int i=0; i<vec.size(); i++){
		for(int j=0; j<vec[i].size(); j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}	
	return 0;
}
