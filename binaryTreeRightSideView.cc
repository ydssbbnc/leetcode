/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
*/
#include<vector>
#include<queue>
#include<map>
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
      vector<int>view;
      queue<pair<TreeNode*,int>>Q;
      if(root){
	Q.push(make_pair(root,0));
      }
      while(!Q.empty()){
	auto node=Q.front().first;
	auto dep=Q.front().second;
	Q.pop();
	if(view.size()==dep){
	  view.push_back(node->val);
	}else{
	  view[dep]=node->val;
	}
	if(node->left)
	  Q.push(make_pair(node->left,dep+1));
	if(node->right)
	  Q.push(make_pair(node->right,dep+1));
      }
      return view;
    }
};
int main(){
  TreeNode a(1),b(2),c(3),d(4),e(5);
  a.left=&b;a.right=&c;b.left=&d;b.right=&e;
  Solution s1;
  auto result=s1.rightSideView(&a);
  cout<<"result:\n";
  for(auto const&e:result)
    cout<<e<<" ";
  cout<<endl;
}
/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Right Side View.
Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Binary Tree Right Side View.
time:O(n)
space:O(lgn)
*/
