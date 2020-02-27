/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>result;
    int allSet=1<<nums.size();
    for(int i=0;i<allSet;++i){
      vector<int>item;
      for(int j=0;j<nums.size();++j)
	if(i&(1<<j))
	  item.push_back(nums[j]);
      result.push_back(item);
    }
    return result;
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
  auto res=s1.subsets(nums);
  cout<<"result: "<<endl;
  for(auto const&e:res){
    for(auto const&e1:e)
      cout<<"["<<e1<<"] ";
    cout<<endl;
  }
}
/*
time:O(n)
space:O(n)
Runtime: 4 ms, faster than 98.32% of C++ online submissions for Subsets.
Memory Usage: 12.4 MB, less than 30.51% of C++ online submissions for Subsets.
*/
