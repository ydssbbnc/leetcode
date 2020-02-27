/*
There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
*/
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp=[](const vector<int>&a,const vector<int>&b)->bool{
            return a.front()<b.front();
        };
        if(points.size()==0)
            return 0;
        sort(points.begin(),points.end(),cmp);
        int shoot_num=1;
        int shoot_begin=points[0].front();
        int shoot_end=points[0].back();
        for(int i=1;i<points.size();++i){
            if(points[i].front()<=shoot_end){
                shoot_begin=points[i].front();
                if(shoot_end>points[i].back()){
                    shoot_end=points[i].back()   ;
                }
            }else{
                ++shoot_num;
                shoot_begin=points[i].front();
                shoot_end=points[i].back();
            }
        }
        return shoot_num;
    }
};
int main(){
  cout<<"input (  -1 representing end a vector,-2 represening all vectors ):\n";
  vector<vector<int>>points{
			    {10,16},
			    {2,8},
			    {1,6},
			    {7,12}
  };
  for(auto const&e:points){
    for(auto const&e1:e){
      cout<<e1<<"\t";
    }
    cout<<endl;
  }
  Solution s1;
  cout<<"result: "<<s1.findMinArrowShots(points)<<endl;
}
/*
Runtime: 144 ms, faster than 53.90% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
Memory Usage: 27 MB, less than 100.00% of C++ online submissions for Minimum Number of Arrows to Burst Balloons.
time:O(n)
space:O(1)
 */
