/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
class Solution {
public:
    int reverse(int x) {
      try{
      string s=to_string(x),t="-";
      int len=s.size();
      for(int i=len-1;i>=0;--i)
	t+=s[i];
      if(x>0)t=t.substr(1,len);
      else t=t.substr(0,len);
	return stoi(t);
      }catch(exception&e){
	return 0;
      }
    }
};
int main(int argc,char**argv){
  Solution s1;
  cout<<  s1.reverse(atoi(argv[1]))<<endl;
}
/*
Runtime: 4 ms, faster than 68.40% of C++ online submissions for Reverse Integer.
Memory Usage: 8.7 MB, less than 9.52% of C++ online submissions for Reverse Integer.
time:O(bits of x)
space:(bits of x)
*/
