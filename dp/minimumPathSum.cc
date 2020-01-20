/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==0||n==0)return 0;
        int dp[m][n]={0};
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;++i)
            dp[i][0]=dp[i-1][0]+grid[i][0];
        for(int i=1;i<n;++i)        
            dp[0][i]=dp[0][i-1]+grid[0][i];
        for(int i=1;i<m;++i)
            for(int j=1;j<grid[i].size();++j)
                dp[i][j]=dp[i-1][j]<dp[i][j-1]?(dp[i-1][j]+grid[i][j]):(dp[i][j-1]+grid[i][j]);
        return dp[m-1][n-1];
    }
};
int main(int argc,char**argv){
  vector<vector<int>>grid{
			  {1,3,1},
			  {1,5,1},
			  {4,2,1}
  };
  Solution s1;
  printf("result = %d\n",s1.minPathSum(grid));
}
/*
Runtime: 8 ms, faster than 87.75% of C++ online submissions for Minimum Path Sum.
Memory Usage: 10.8 MB, less than 52.63% of C++ online submissions for Minimum Path Sum.
time: O(m*n)
space: O(m*n)
*/
