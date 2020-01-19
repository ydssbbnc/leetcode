/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        int dp_is1=nums[1]>nums[0]?nums[1]:nums[0],dp_is2=nums[0],dp_i=dp_is1;
        for(int i=2;i<n;++i){
            dp_i=(nums[i]+dp_is2)>dp_is1?(nums[i]+dp_is2):dp_is1;
            dp_is2=dp_is1;
            dp_is1=dp_i;
        }
        return dp_i;
    }
};
int main(int argc,char**argv){
  vector<int>nums;
  for(int i=1;i<argc;++i)
    nums.push_back(atoi(argv[i]));
  Solution s1;
  printf("result = %d\n",s1.rob(nums));
}
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
Memory Usage: 8.6 MB, less than 83.02% of C++ online submissions for House Robber.
time: O(n)
space: O(1)
*/
