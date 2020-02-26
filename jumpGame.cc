/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>index;
        for(int i=0;i<nums.size();++i){
            index.push_back(i+nums[i]);
        }
        int jump=0;
        int maxIndex=index[0];
        while(jump<index.size()&&jump<=maxIndex){
            if(maxIndex<index[jump]){
                maxIndex=index[jump];
            }
            ++jump;
        }
        if(jump==index.size()){
            return true;
        }
        return false;
    }
};
int main(){
  cout<<"input (end with -1): "<<endl;
  vector<int>nums;
  int in;
  while(cin>>in){
    if(in==-1)break;
    nums.push_back(in);
  }
  Solution s1;
  cout<<"result: "<<s1.canJump(nums)<<endl;
}
/*
Runtime: 8 ms, faster than 97.25% of C++ online submissions for Jump Game.
Memory Usage: 10.5 MB, less than 10.53% of C++ online submissions for Jump Game.
*/
