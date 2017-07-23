/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

*/

#include<iostream>

using namespace std;
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if( m== n)
            return head;
        ListNode *p, *pre, *tail, *q;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        
        pre=dummy;
        p=head;
        int i=1;
        while(i++ <= m-1){
            pre=p;
            p=p->next;
        }
        
        tail=p; 
        q=p->next;
      
        p=p->next;
        int t=n-m;
        while(t-- && p){
            q=p->next;
            p->next=pre->next;
            pre->next=p;
            p=q;
        }
        
        tail->next=q;
         
        head=dummy->next; 
        delete dummy;
        return  head;
    }
};

int main(){
	ListNode *head=new ListNode(1);
	ListNode *tail=head;
	tail->next=new ListNode(2);
	tail=tail->next;
	
	tail->next=new ListNode(3);
	tail=tail->next;

  	ListNode *p=head;
    while(p){
		cout<<p->val<<endl;
		p=p->next;
	}

	
	
	Solution solution;

	head=solution.reverseBetween(head, 2, 3);
	p=head;
	while(p){
		cout<<p->val<<endl;
		p=p->next;
	}

	return 0;
}
