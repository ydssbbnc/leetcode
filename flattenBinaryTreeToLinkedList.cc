/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/
#include<iostream>
using namespace std;
struct TreeNode{
  int val;
  TreeNode*left,*right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution{
  void preorder(TreeNode*node,TreeNode*&last){
    if(!node)return;
    if(!node->left&&!node->right){
      last=node;
      return;
    }
    auto left=node->left;
    auto right=node->right;
    TreeNode*left_last=nullptr;
    TreeNode*right_last=nullptr;
    if(left){
      preorder(left,left_last);
      node->left=nullptr;
      node->right=left;
      last=left_last;
    }
    if(right){
      preorder(right,right_last);
      if(left_last){
	left_last->right=right;
      }
      last=right_last;
    }
  }
public:
  void flatten(TreeNode*root){
    TreeNode*last=nullptr;
    preorder(root,last);
  }
};
int main(){
  TreeNode a(1),b(2),c(3),d(4),e(5);
  a.left=&b;a.right=&c;b.left=&d;b.right=&e;
  Solution s1;
  s1.flatten(&a);
  TreeNode*p=&a;
  while(p){
    cout<<p->val<<" ";
    p=p->right;
  }
  puts("");
}
/*
Runtime: 8 ms, faster than 74.64% of C++ online submissions for Flatten Binary Tree to Linked List.
Memory Usage: 10.8 MB, less than 8.33% of C++ online submissions for Flatten Binary Tree to Linked List.
time:O(n)
space:O(nlgn)
*/
