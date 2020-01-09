/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
*/
#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
  int val;
  ListNode*next;
  ListNode(int x):val(x),next(nullptr){}
};
class Solution {
public:
  static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(!l1)return l2;
    if(!l2)return l1;
    int carry=0,t=0;
    ListNode* p=l1;
    ListNode* q=l2;
    while((p->next)&&(q->next)){
      t=p->val+q->val+carry;
      p->val=t%10;
      carry=t/10;
      p=p->next;
      q=q->next;
    }
    t=p->val+q->val+carry;
    p->val=t%10;
    carry=t/10;
    if(!(p->next)&&!(q->next)){
      if(carry)
	p->next=new ListNode(carry);
      return l1;
    }
    if(!(p->next)&&(q->next)){
      p->next=q->next;
      q=q->next;
      while(q->next){
	t=(q->val+carry);
	q->val=t%10;
	carry=t/10;
	q=q->next;
      }
      t=(q->val+carry);
      q->val=t%10;
      carry=t/10;
      if(carry)
	q->next=(new ListNode(carry));
      return l1;
    }
    if((p->next)&&!(q->next)){
      p=p->next;
      while(p->next){
	t=(p->val+carry);
	p->val=t%10;
	carry=t/10;
	p=p->next;
      }
      t=(p->val+carry);
      p->val=t%10;
      carry=t/10;
      if(carry)
	p->next=(new ListNode(carry));
      return l1;
    }
      return l1;
  }
};
int main(){
  ListNode *l1,*l2,*p,*q;
  vector<int>v1,v2;
  int t=0;
  cout<<"input numbers(end with -1):"<<endl;
  while((cin>>t)&&(t!=-1))
    v1.push_back(t);
  cout<<"input numbers for second list(end with -1):"<<endl;
  while((cin>>t)&&(t!=-1))
    v2.push_back(t);
  l1=new ListNode(v1[0]);
  p=l1;
  for(int i=0;i<v1.size()-1;++i){
      q=new ListNode(v1[i+1]);
      p->next=q;
      p=q;
  }
  l2=new ListNode(v2[0]);
  p=l2;
  for(int i=0;i<v2.size()-1;++i){
      q=new ListNode(v2[i+1]);
      p->next=q;
      p=q;
  }
  cout<<"遍历l1:\t";
  for(p=l1;p;p=p->next){
    cout<<p->val<<"  ";
  }
  cout<<endl;
  cout<<"遍历l2:\t";
  for(q=l2;q;q=q->next)
    cout<<q->val<<"  ";
  cout<<endl;
  cout<<"add l1+l2:\t";
  p=Solution::addTwoNumbers(l1,l2);
  for(q=p;q;q=q->next)
    cout<<q->val<<"  ";
  cout<<endl;
}
/*Output:
Runtime: 40 ms, faster than 5.56% of C++ online submissions for Add Two Numbers.
Memory Usage: 9.8 MB, less than 98.86% of C++ online submissions for Add Two Numbers.
*/
