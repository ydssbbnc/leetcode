/*
A car travels from a starting position to a destination which is target miles east of the starting position.

Along the way, there are gas stations.  Each station[i] represents a gas station that is station[i][0] miles east of the starting position, and has station[i][1] liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.  It uses 1 liter of gas per 1 mile that it drives.

When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

What is the least number of refueling stops the car must make in order to reach its destination?  If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there.  If the car reaches the destination with 0 fuel left, it is still considered to have arrived.

 

Example 1:

Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.
Example 2:

Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can't reach the target (or even the first gas station).
Example 3:

Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: 
We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.
 

Note:

1 <= target, startFuel, stations[i][1] <= 10^9
0 <= stations.length <= 500
0 < stations[0][0] < stations[1][0] < ... < stations[stations.length-1][0] < target
*/
#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
class Solution{
public:
  int minRefuelStops(int target,int startFuel,vector<vector<int>>stations){
    priority_queue<int>Q;
    int result=0;
    stations.push_back({target,0});
    sort(stations.begin(),stations.end(),
	 [](const vector<int>&a,const vector<int>&b){
	   return a.front()<b.front();
	 });
    for(int i=0;i<stations.size();++i){
      while(!Q.empty()&&startFuel<stations[i][0]){
	startFuel+=(Q.top());
	Q.pop();
	++result;
      }
      if(startFuel<stations[i][0])
	return -1;
      Q.push(stations[i].back());
    }
    return result;
  }
};
int main(){
  vector<vector<int>>stations;
  cout<<"input target,startFuel:\n";
  int target,startFuel;
  cin>>target>>startFuel;
  cout<<"initialize stations(end with -1):\n";
  int in1,in2;
  while(cin>>in1>>in2){
    if(in1==-1||in2==-1)break;
    stations.push_back({in1,in2});
  }
  for(auto const&e:stations){
    for(auto const&e1:e)
      cout<<e1<<"\t";
    cout<<endl;
    }
  Solution s1;
  cout<<"result: "<<s1.minRefuelStops( target, startFuel,stations)<<endl;
}
/*
time:O(n)
space:O(1)
Runtime: 28 ms, faster than 91.88% of C++ online submissions for Minimum Number of Refueling Stops.
Memory Usage: 13.2 MB, less than 100.00% of C++ online submissions for Minimum Number of Refueling Stops.
*/
