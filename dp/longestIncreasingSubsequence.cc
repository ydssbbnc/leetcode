/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size(),max=1;
        if(len==0)return 0;
        vector<int>dp(len,1);
        for(int i=1;i<len;++i){
          for(int j=0;j<i;++j)
            if(nums[i]>nums[j]&&(dp[j]+1)>dp[i])
                dp[i]=dp[j]+1;
          max=dp[i]>max?dp[i]:max;
        }
        return max;
    }
};
int main(int argc,char**argv){
  vector<int>nums;
  for(int i=1;i<argc;++i)
    nums.push_back(atoi(argv[i]));
  for(auto const&e:nums)
    printf("%d ",e);
  printf("\n");
  Solution s1;
  printf("result = %d\n",s1.lengthOfLIS(nums));
}
/*
Runtime: 36 ms, faster than 62.38% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 8.7 MB, less than 64.06% of C++ online submissions for Longest Increasing Subsequence.
time: O(n^2)
space: O(n)
*/
