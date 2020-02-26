/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Example 1:

Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.
Example 2:

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
Example 3:

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?
*/
#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2){
            return nums.size();
        }
        static const int BEGIN=0,
        UP=1,DOWN=2;
        int STATE=BEGIN;
        int maxLen=1;
        for(int i=1;i<nums.size();++i){
            switch(STATE){
                case BEGIN:
                    if(nums[i-1]<nums[i]){
                        STATE=UP;
                        ++maxLen;
                    }
                    else if(nums[i-1]>nums[i]){
                        STATE=DOWN;
                        ++maxLen;
                    }
                    break;
                case UP:
                    if(nums[i-1]>nums[i]){
                        STATE=DOWN;
                        ++maxLen;
                    }
                    break;
                case DOWN:
                    if(nums[i-1]<nums[i]){
                        STATE=UP;
                        ++maxLen;
                    }
                    break;                    
            }
        }
        return maxLen;
    }
};
int main(int argc,char**argv){
  vector<int>v;
  cout<<"input (end with -1): "<<endl;
  int in;
  while(cin>>in){
    if(in==-1)break;
    v.push_back(in);
  }
  Solution s1;
  cout<<"result: "<<s1.wiggleMaxLength(v)<<endl;
}
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Wiggle Subsequence.
Memory Usage: 8.8 MB, less than 30.00% of C++ online submissions for Wiggle Subsequence.
*/
