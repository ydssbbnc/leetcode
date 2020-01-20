/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
#include<vector>
#include<stdio.h>
#include<string>
using namespace std;
struct Solution{
    int minimumTotal(vector<vector<int>>& t) {
        int len=t.size();
        vector<int> dp=t[len-1];
        for(int i=len-2;i>=0;--i)
            for(int j=0;j<t[i].size();++j)
                dp[j]=dp[j]<dp[j+1]?(dp[j]+t[i][j]):(dp[j+1]+t[i][j]);
        return dp[0];
    }
};
int main(int argc,char**argv){
  vector<vector<int>>t{
		       {2},
		       {3,4},
		       {6,5,7},
		       {4,1,8,3}
  };
  for(int i=0;i<t.size();++i){
    for(int j=0;j<t[i].size();++j)
      printf("%d ",t[i][j]);
    printf("\n");    
  }
  Solution s1;
  printf("result = %d\n",s1.minimumTotal(t));
}
/*
Runtime: 4 ms, faster than 96.52% of C++ online submissions for Triangle.
Memory Usage: 9.7 MB, less than 91.30% of C++ online submissions for Triangle.
time: O(n^2)
space: O(n)
*/
