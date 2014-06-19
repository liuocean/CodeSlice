/*
模板类与非模板类的区别

*/


#include<iostream>

using namespace std;

int b=0, d=0;

template<class T>
class Base{
public:
	static int func(){
		static int num=b++;
		return num;
	}
};

class Derived{
public:
	static int func(){
		static int num=d++;
		return num;
	}
};

int main(){
	cout<<Base<int>::func()<<endl;
	cout<<Base<char>::func()<<endl;
	cout<<Base<long>::func()<<endl;
	
	cout<<Derived::func()<<endl;
	cout<<Derived::func()<<endl;
	cout<<Derived::func()<<endl;
	
	return 0;
}
