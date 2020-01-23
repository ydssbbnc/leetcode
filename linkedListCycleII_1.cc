/*Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.


 

Follow-up:
Can you solve it without using extra space?
*/
#include<stdio.h>
#include<set>
using namespace std;
int main(int argc,char**argv){
  struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x):val(x),next(nullptr){}
  };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      while(head){
        if(!less<ListNode*>()(head,head->next))
          return head->next;
        head=head->next;
      }
      return nullptr;
    }
};
  ListNode a(1),b(2),c(3),d(4),e(5),f(6);
  a.next=&b;b.next=&c;c.next=&d;d.next=&e;e.next=&f;f.next=&c;
  ListNode*h=&a,*h1=h;
  while(!less<ListNode*>()(h1,h1->next)){
    printf("%d\n",h1->val);
    h1=h1->next;
  }
  printf("%d\n",h1->val);
  Solution s1;
  printf("result = %d\n",*s1.detectCycle(h)->next);
  return 0;
}
/*
Runtime: 16 ms, faster than 29.80% of C++ online submissions for Linked List Cycle II.
Memory Usage: 9.7 MB, less than 90.48% of C++ online submissions for Linked List Cycle II.
time: O(n)
space: O(1)
*/
