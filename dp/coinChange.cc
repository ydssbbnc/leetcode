/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      vector<int>dp(amount+1,-1);
      dp[0]=0;
      for(int i=1;i<=amount;++i)
	for(int &e:coins){
	  if(i<e||dp[i-e]==-1)continue;
	  if(dp[i]==-1||dp[i]>dp[i-e]+1)
	    dp[i]=dp[i-e]+1;
	}
       return dp[amount];
    }
};
int main(int argc,char**argv){
  vector<int>coins;
  printf("coins: ");
  for(int i=2;i<argc;++i){
    coins.push_back(atoi(argv[i]));
    printf("%d ",coins[i-2]);
  }
  printf("\namount:%d ",atoi(argv[1]));
  Solution s1;
  printf("\nresult = %d\n",s1.coinChange(coins,atoi(argv[1])));
}
/*
Runtime: 32 ms, faster than 93.86% of C++ online submissions for Coin Change.
Memory Usage: 12.6 MB, less than 84.31% of C++ online submissions for Coin Change.
time: O(amount*coins.size())
space: O(amount)
*/
