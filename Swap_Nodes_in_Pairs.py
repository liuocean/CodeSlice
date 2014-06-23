"""
Swap Nodes in Pairs Total Accepted: 14822 Total Submissions: 46443 My Submissions
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

"""
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        dummyHead=ListNode(0)
        tail=dummyHead
        p=head
        while p is not None:
            if p.next is None:
                tail.next=p
                p=p.next
            else:
                l1=p;l2=p.next
                p=l2.next
                tail.next=l2
                l2.next=l1
                l1.next=None
                tail=l1
        return dummyHead.next

if __name__ == "__main__":
    head=ListNode(1)
    head.next=ListNode(2)

    solution=Solution();
    head=solution.swapPairs(head)

    p=head
    while p is not None:
        print p.val
        p=p.next

        
    
