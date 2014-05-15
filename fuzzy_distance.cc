/*
http://www.ituring.com.cn/article/53581

模糊距离分析
原题

X和Y都是只有0和1组成的字符串。D(X,Y)称为模糊距离，
定义如下： 首先删除X和Y从头开始的公共子串 然后将X和Y剩下部分的长度相加得到模糊距离 
例如D(1000,1111)，首先，删除子串“1”，然后剩下“000”和“111”长度都是3，相加为6，则 D(1000,1111)=6。 
例如D(101,1100)，首先删除公共子串“1”，然后剩下"01"和"100"长度分别为2，3，相加为5，则 D(101,1100)=5。
问题是，给定n个只有0和1的字符串，如：

1111
1000
101
1100
... 

请找到最大的模糊距离，字符串总数为n，字符串最长为m。

*/

#include<iostream>
#include<cstring>

using namespace std;

typedef struct trie_node trie_node_t;
struct trie_node{ //trie树节点
	enum { SIZE=2 };   // 别忘了分号 ；
	int  value; //这里表示树的深度
	struct trie_node * children[SIZE];
	
	trie_node(){
		value=0;
		for(int i=0; i<SIZE; i++)
			children[i]=NULL;
	}
};  //// 别忘了分号 ；

typedef struct trie trie_t;
struct trie{
	trie_node *root; //根节点
	int count;//单词总数
	
	trie(){
		root=NULL;
		count=0;
	}
};

bool insert(trie_t *ptrie, char* key){
	if(!ptrie || !key || strlen(key)==0)
		return false;
	if(!ptrie->root){
		ptrie->root=new trie_node_t();
	}
	trie_node_t *p=ptrie->root;
	
	while(*key){
		int index=*key-'0';
		if(index > p->children[index]->SIZE)
			return false;
		
		int depth=strlen(key);//剩余字符串长度，也即节点深度
		
		if(p->children[index] == NULL){ //子节点不存在，新建
			p->children[index]=new trie_node_t();
			p->children[index]->value=depth;
		}
		else{
			if(depth > p->children[index]->value) //每插入节点，更新value，使得value是所有子节点的最大深度
				p->children[index]->value=depth;
		}
		
		p=p->children[index];
		key++;	
	}
	
	return true;
}

bool search(trie_t *ptrie, char *key){
	if(!ptrie || !ptrie->root || !key || strlen(key)==0)
		return false;
	
	trie_node_t *p=ptrie->root;
	while(*key){
		int index=*key - '0';
		if(index > p->children[index]->SIZE)
			return false;
			
		if(p->children[index] == NULL)
			return false;
		else {
			p=p->children[index];
		}
		
		key++;
	}
	
	return true;
}


void get_fuzzy_distance(trie_node_t *root, int &max){
	if(!root){
		max=0;
		return 0;
	}
	int temp=0;
	if(root->children[0] && root->children[1]){
		temp=root->children[0]->value + root->children[1]->value ; //		
	}
	else temp=root->children[0] ? root->children[0]->value : root->children[1]->value;
	
	if(temp > max)
		max =temp;
	
	int left=0, right=0;
	get_fuzzy_distance(root->children[0], left);
	get_fuzzy_distance(root->children[1], right);
	
	if(left > max)
		max=left;
	if(right > max)
		max=right;
}

void display(trie_node_t *root){	//打印trie树	
}

int main(){
	trie_t *ptrie =new trie_t();
	insert(ptrie, "1111");
	insert(ptrie, "1000");
	insert(ptrie, "101");
	insert(ptrie, "1100");
	
	bool res=search(ptrie, "100");
	if(res)
		cout<<"hah"<<endl;
	else cout<<"Oops"<<endl;
	
	int distance=0;
	get_fuzzy_distance(ptrie->root, distance);
	cout<<distance<<endl;
	
	return 0;
}