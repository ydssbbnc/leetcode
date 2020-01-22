/*Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
 */
#include<stdio.h>
struct ListNode{
  int val;
  ListNode*next;
  ListNode():next(nullptr){}
  ListNode(int x):val(x),next(nullptr){}
};;
class Solution{
public:
  ListNode*reverseList(ListNode*h){
    if(!h||!(h->next))return h;
    ListNode *p=h->next,*q=p->next;
    h->next=nullptr;
    while(q){
      p->next=h;
      h=p;
      p=q;
      q=q->next;
    }
    p->next=h;
    return h=p;
  }
};
int main(){
  Solution s1;
  ListNode a(1),b(2),c(3),d(4),e(5);
  a.next=&b;b.next=&c;
  c.next=&d;d.next=&e;
  ListNode*h=&a;
  printf("Before reversing:\n");
  while(h){
    printf("%d\n",h->val);
    h=h->next;
  }
  h=&a;
  h=s1.reverseList(h);
  printf("After reversing:\n");
  while(h){
    printf("%d\n",h->val);
    h=h->next;
  }
  return 0;
}
/*
Runtime: 16 ms, faster than 6.32% of C++ online submissions for Reverse Linked List.
Memory Usage: 9.7 MB, less than 5.34% of C++ online submissions for Reverse Linked List.
time: O(n)
space: O(1)
*/
