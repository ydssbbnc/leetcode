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
  int biSearch(vector<int>&nums,int t){
    int i=0,j=nums.size()-1;
    while(i<=j){
      if(nums[(i+j)/2]==t)
	return (i+j)/2;
      if(nums[(i+j)/2]<t)
	i=(i+j)/2+1;
      else
	j=(i+j)/2-1;
    }
    return i>j?i:j;
  }
  int lengthOfLIS(vector<int>& nums) {
    int len=nums.size();
    if(len==0)return 0;
    vector<int>stack;
    stack.push_back(nums[0]);
    for(int i=1;i<len;++i)
      stack[biSearch(stack,nums[i])]=nums[i];
    return stack.size();
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
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 8.7 MB, less than 62.50% of C++ online submissions for Longest Increasing Subsequence.
time: O(n*lgn)
space: O(n)
*/
