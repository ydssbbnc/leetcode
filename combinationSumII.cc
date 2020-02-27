/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>item;
        set<vector<int>>resSet;
        sort(candidates.begin(),candidates.end());
        generate(0,candidates,result,item,resSet,0,target);
        return result;
    }
private:
    void generate(int i,vector<int>&nums,
                 vector<vector<int>>&result,
                 vector<int>&item,
                 set<vector<int>>&resSet,
                 int sum,int target){
        if(i>=nums.size()||sum>target)
            return;
        sum+=nums[i];
        item.push_back(nums[i]);
        if(target==sum &&resSet.find(item)==resSet.end()){
            result.push_back(item);
            resSet.insert(item);
        }
        generate(i+1,nums,result,item,resSet,sum,target);
        sum-=nums[i];
        item.pop_back();
        generate(i+1,nums,result,item,resSet,sum,target);
    }
};
int main(){
  cout<<"input target: "<<endl;
  int target;
  cin>>target;
  cout<<"\ninput nums(end with -1):"<<endl;
  int in;
  vector<int>nums;
  while((cin>>in)&&in!=-1)
    nums.push_back(in);
  Solution s1;
  auto result=s1.combinationSum2(nums,target);
  cout<<"result: "<<endl;
  for(auto const&e:result){
    for(auto const&e1:e)
      cout<<"["<<e1<<"] ";
    cout<<endl;
  }
}
/*
time:O(n)
space:O(n)
Runtime: 100 ms, faster than 8.89% of C++ online submissions for Combination Sum II.
Memory Usage: 15.5 MB, less than 5.26% of C++ online submissions for Combination Sum II.
*/
