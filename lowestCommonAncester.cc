/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]


 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
  void preorder(TreeNode*node,TreeNode*search,vector<TreeNode*>&path,vector<TreeNode*>&result,bool &finish){
      if(!node||finish)
          return;
      path.push_back(node);
      if(node==search){
          finish=true;
          result=path;    
      }
      preorder(node->left,search,path,result,finish);
      preorder(node->right,search,path,result,finish);      
      path.pop_back();      
  }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path;
        vector<TreeNode*>p_path;
        vector<TreeNode*>q_path;
        bool finish=false;
        preorder(root,p,path,p_path,finish);
        path.clear();
        finish=false;
        preorder(root,q,path,q_path,finish);
        int path_len=0;
        if(p_path.size()<q_path.size()){
            path_len=p_path.size();
        }else{
            path_len=q_path.size();
        }
        TreeNode*result=0;
        for(int i=0;i<path_len;++i){
            if(p_path[i]==q_path[i]){
                result=p_path[i];
            }
        }
        return result;
    }
};
int main(){
  TreeNode a(1),b(2),c(3),d(4),e(5);
  a.left=&b;a.right=&c;b.left=&d;b.right=&e;
  Solution s1;
  auto result=s1.lowestCommonAncestor(&a,&e,&d);
  cout<<"result: "<<result->val<<endl;
}
/*
time:O(n)
space:O(n)
*/
