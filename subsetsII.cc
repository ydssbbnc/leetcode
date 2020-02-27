/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.
*/
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums){
    sort(nums.begin(),nums.end());
    set<vector<int>>resSet;
    vector<int>item;
    vector<vector<int>>result;
    result.push_back(item);
    generate(0,nums,item,result,resSet);
    return result;
  }
private:
  void generate(int i,vector<int>&nums,
		vector<int>&item,
		vector<vector<int>>&result,
		set<vector<int>>&resSet){
    if(i>=nums.size())
      return;
    item.push_back(nums[i]);
    if(resSet.find(item)==resSet.end()){
      result.push_back(item);
      resSet.insert(item);
    }
    generate(i+1,nums,item,result,resSet);
    item.pop_back();
    generate(i+1,nums,item,result,resSet);
  }
};
int main(){
  cout<<"input (end with -1):\n";
  vector<int>nums;
  int in;
  while(cin>>in){
    if(in==-1)break;
    nums.push_back(in);
  }
  Solution s1;
  cout<<"result: \n";
  auto result=s1.subsetsWithDup(nums);
  for(auto const&e:result){
    for(auto const&e1:e)
      cout<<"["<<e1<<"] ";
    cout<<endl;
  }
}
/*
Runtime: 4 ms, faster than 99.60% of C++ online submissions for Subsets II.
Memory Usage: 16.2 MB, less than 13.64% of C++ online submissions for Subsets II.
time:O(n)
space:O(n)
*/
