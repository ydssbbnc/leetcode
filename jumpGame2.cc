/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.
*/
#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
  int jump(vector<int>&nums){
    if(nums.size()<2)return 0;
    int res=1;
    int curM=nums[0],preM=curM;
    for(int i=1;i<nums.size();++i){
      if(i>curM){
	cout<<nums[curM]<<'\t';
	++res;
	curM=preM;
      }
      if(preM<nums[i]+i)
	preM=nums[i]+i;
    }
    return res;
  }
};
int main(){
  vector<int>nums;
  cout<<"input (end with -1):\n";
  int in;
  while(cin>>in){
    if(in==-1)break;
    nums.push_back(in);
  }
  Solution s1;
  int res=s1.jump(nums);
  cout<<"\nresult: "<<res<<endl;
}
/*
Runtime: 12 ms, faster than 71.88% of C++ online submissions for Jump Game II.
Memory Usage: 10.2 MB, less than 80.00% of C++ online submissions for Jump Game II.
time:O(n)
space:O(1)
*/
