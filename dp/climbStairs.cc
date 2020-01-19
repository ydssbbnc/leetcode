/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
#include<stdio.h>
#include<string>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)return n;
        int dp_is1=2,dp_is2=1,dp_i=2;
        for(int i=3;i<=n;++i){
            dp_i=dp_is1+dp_is2;
            dp_is2=dp_is1;
            dp_is1=dp_i;
        }
        return dp_i;
    }
};
int main(int argc,char**argv){
  Solution s1;
  printf("n = %d\nresult = %d\n",atoi(argv[1]),s1.climbStairs(atoi(argv[1])));
}
/*
Runtime: 4 ms, faster than 53.01% of C++ online submissions for Climbing Stairs.
Memory Usage: 8.2 MB, less than 92.65% of C++ online submissions for Climbing Stairs.
time: O(n)
space: O(1)
*/
