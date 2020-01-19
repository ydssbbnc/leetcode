/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
#include<stdio.h>
#include<vector>
#include<string>
using  namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int dp_is1=nums[0],dp_i,max=dp_is1;
        for(int i=1;i<n;++i){
            dp_i=(dp_is1)>0?(dp_is1+nums[i]):nums[i];
            max=max>dp_i?max:dp_i;
            dp_is1=dp_i;
        }
        return max;
    }
};
int main(int argc,char**argv){
  vector<int>nums;
  for(int i=1;i<argc;++i)
    nums.push_back(atoi(argv[i]));
  Solution s1;
  printf("result = %d\n",s1.maxSubArray(nums));
}
/*
Runtime: 8 ms, faster than 72.33% of C++ online submissions for Maximum Subarray.
Memory Usage: 9.3 MB, less than 82.35% of C++ online submissions for Maximum Subarray.
time: O(n)
space: O(1)
*/
