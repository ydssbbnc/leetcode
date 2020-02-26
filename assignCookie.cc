/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive.
You cannot assign more than one cookie to one child.

Example 1:
Input: [1,2,3], [1,1]

Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:
Input: [1,2], [1,2,3]

Output: 2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
*/
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;
class Solution {
public:
  static     int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(g.begin(),g.end());
      sort(s.begin(),s.end());
      int child=0,cookie=0;
      while(child<g.size()&&cookie<s.size()){
        if(g[child]<=s[cookie]){
          ++child;
        }
        ++cookie;
      }
      return child;
    }
};
int main(int argc,char**argv){
  vector<int>g,s;
  cout<<"input g(end with -1):\n";
  int in;
  while((cin>>in)){
    if(in==-1)break;
    g.push_back(in);
  }
  cout<<"input s(end with -1):\n";
  while((cin>>in)){
    if(in==-1)break;
    s.push_back(in);
  }
  cout<<"result: "  <<Solution::findContentChildren(g,s)<<endl;
  
}
/*
Runtime: 32 ms, faster than 98.77% of C++ online submissions for Assign Cookies.
Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Assign Cookies.
 */
