/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
public:
  vector<string> generateParenthesis(int n) {
    vector<string>result;
    generate(n,n,"",result);
    return result;
  }
private:
  void generate(int left,int right,string item,vector<string>&result){
    if(!left&&!right){
      result.push_back(item);
      return;
    }
    if(left>0)
      generate(left-1,right,item+'(',result);
    if(right>left)
      generate(left,right-1,item+')',result);
  }
};
int main(){
  cout<<"input n:\n";
  int in;
  cin>>in;
  Solution s1;
  cout<<"result: "<<endl;
  auto result=s1.generateParenthesis(in);
  for(auto const&e: result)
    cout<<e<<endl;
}
/*
Runtime: 8 ms, faster than 56.71% of C++ online submissions for Generate Parentheses.
Memory Usage: 17.3 MB, less than 61.16% of C++ online submissions for Generate Parentheses.
time:O(n)
space:O(n)
*/
