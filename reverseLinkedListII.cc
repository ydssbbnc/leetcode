/*Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
 */
#include<string>
#include<stdio.h>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* h, int m, int n) {
        if(!h||!(h->next)||m>=n||m<1)return h;
        int repeat=n-m+1,m1=m;
        ListNode *p=nullptr,*q=h,*r,*p1,*p2;
        while(m1>1&&--m){
            p=q;
            q=q->next;
        }
        p1=p;
        p2=q;
	    r=q->next;
        while(repeat--){
            q->next=p;
            p=q;
            q=r;
            if(r)
                r=r->next;
            else
                break;
        }
        if(m1==1)
            h=p;
        else
        	p1->next=p; 
        p2->next=q;
        return h;
    }
};
int main(int argc,char**argv){
  ListNode a(1),b(2),c(3),d(4),e(5),f(6);
  a.next=&b;b.next=&c;
  c.next=&d;d.next=&e;
  e.next=&f;ListNode*h=&a;
  while(h){
    printf("%d\n",h->val);
    h=h->next;
  }
  h=&a;
  Solution s1;
  h=s1.reverseBetween(h,atoi(argv[1]),atoi(argv[2]));
  while(h){
    printf("%d\n",h->val);
    h=h->next;
  }
}
/*
Runtime: 8 ms, faster than 5.27% of C++ online submissions for Reverse Linked List II.
Memory Usage: 8.9 MB, less than 6.25% of C++ online submissions for Reverse Linked List II.
time: O(n)
space: O(1)
*/
