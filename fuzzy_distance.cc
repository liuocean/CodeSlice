/*
http://www.ituring.com.cn/article/53581

ģ���������
ԭ��

X��Y����ֻ��0��1��ɵ��ַ�����D(X,Y)��Ϊģ�����룬
�������£� ����ɾ��X��Y��ͷ��ʼ�Ĺ����Ӵ� Ȼ��X��Yʣ�²��ֵĳ�����ӵõ�ģ������ 
����D(1000,1111)�����ȣ�ɾ���Ӵ���1����Ȼ��ʣ�¡�000���͡�111�����ȶ���3�����Ϊ6���� D(1000,1111)=6�� 
����D(101,1100)������ɾ�������Ӵ���1����Ȼ��ʣ��"01"��"100"���ȷֱ�Ϊ2��3�����Ϊ5���� D(101,1100)=5��
�����ǣ�����n��ֻ��0��1���ַ������磺

1111
1000
101
1100
... 

���ҵ�����ģ�����룬�ַ�������Ϊn���ַ����Ϊm��

*/

#include<iostream>
#include<cstring>

using namespace std;

typedef struct trie_node trie_node_t;
struct trie_node{ //trie���ڵ�
	enum { SIZE=2 };   // �����˷ֺ� ��
	int  value; //�����ʾ�������
	struct trie_node * children[SIZE];
	
	trie_node(){
		value=0;
		for(int i=0; i<SIZE; i++)
			children[i]=NULL;
	}
};  //// �����˷ֺ� ��

typedef struct trie trie_t;
struct trie{
	trie_node *root; //���ڵ�
	int count;//��������
	
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
		
		int depth=strlen(key);//ʣ���ַ������ȣ�Ҳ���ڵ����
		
		if(p->children[index] == NULL){ //�ӽڵ㲻���ڣ��½�
			p->children[index]=new trie_node_t();
			p->children[index]->value=depth;
		}
		else{
			if(depth > p->children[index]->value) //ÿ����ڵ㣬����value��ʹ��value�������ӽڵ��������
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

void display(trie_node_t *root){	//��ӡtrie��	
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