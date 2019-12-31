#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*Given a array of integers,return indices of the two numbers such that they add up to a \
specific target.
  You may assume that each input would have exactly one solution,and you may not use the \
same element twice.
time: O(n)
space: O(n)
*/
struct Solution{
  static  std::vector<int>twoSum(std::vector<int>&nums,int target){
    std::unordered_map<int,int>um;
    int i=0,j=0;
    for(;i<nums.size();++i)
      um[nums[i]]=i;
    for(;j<nums.size();++j){
        i=(target-nums[j]);
        if(um.count(i)&&j!=um[i])
            break;
    }
    return {um[i],j};
  }
};
int main(){
  vector<int>input_ivec,res;
  int target;
  cout<<"input nums: "<<endl;
  for(int i=0,j=0;(cin>>j)&&j!=-1;++i)//end input by -1
    input_ivec.push_back(j);
  cout<<"original input_ivec: ";
  for(auto const &e:input_ivec)
    cout<<e<<" ";
  cout<<endl<<"input target: ";
  cin>>target;
  res=Solution::twoSum(input_ivec,target);
  cout<<"subscript: "<<res[0]<<" "<<res[1]<<endl;
  cout<<input_ivec[res[0]]<<" + "<<input_ivec[res[1]]<<" = "<<target<<endl;
}
/*execute:
input nums: 
2 7 11 15 -1
original input_ivec: 2 7 11 15 
input target: 9
subscript: 0 1
2 + 7 = 9
*/
