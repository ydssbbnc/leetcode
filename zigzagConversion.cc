/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/
#include<string>
#include<iostream>
using namespace std;
class Solution {
public://14:38
    string convert(string &s, int n) {
        if(n<2)       
            return s;
        int len=s.length(),si=2*n-2;
        string ret="";
	for(int i=0;i<len;i=i+2*n-2)
	  ret+=s[i];
          for(int i=1;i<n-1;++i)
            for(int j=i;j<len;j+=((j%si)<n ? (si-2*i):2*i))
                ret+=s[j];
	  cout<<endl;
	  for(int i=n-1;i<len;i=i+si)
	    ret+=s[i];	    
        return ret;
    }
};
int main(){
  string s="PAYPALISHIRING";
  Solution sn;
  cout<<"s: "<<s<<endl;
  cout<<sn.convert(s,4)<<endl;
  
}
/*Runtime: 12 ms, faster than 76.67% of C++ online submissions for ZigZag Conversion.
Memory Usage: 10 MB, less than 98.15% of C++ online submissions for ZigZag Conversion.
space:O(1)   
time:O(s.length())
*/
