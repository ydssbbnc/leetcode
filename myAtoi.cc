/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/
#include<iostream>
#include<limits.h>
#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int start=0,len=str.length();
        if(len<1)return 0;
        while(start<len&&str[start]==' ')
            ++start;
        if(start==len||!(str[start]>=48&&str[start]<=57||str[start=='+'||str[start]=='-']))return 0;
        int ret=0,y=0,m=INT_MAX/10;char tag=str[start];
	//cout<<"m: "<<m<<endl<<"INT_MAX: "<<INT_MAX<<endl;
        if(tag=='+'||tag=='-')++start;
        while(start<len&&(str[start]>=48&&str[start]<=57)){
            y=str[start]-48;
            if(tag!='-'&&(ret>m||(ret==m&&y>=7)||(INT_MAX-ret*10)<=y))
              return INT_MAX;   
            if(tag=='-'&&(ret>m||(ret==m&&y>=8)||(INT_MAX-ret*10+1)<=y))
              return INT_MIN;  
            ret=ret*10+y;
            ++start;
        }
        return tag=='-'?-ret:ret;        
    }
};
int main(int argc,char**argv){
  cout<<"INT_MAX: "<<INT_MAX<<endl<<"INT_MIN: "<<INT_MIN<<endl;
  Solution sl;
  cout<<"input: "<<argv[1]<<endl<<"output: "<< sl.myAtoi((argv[1]))<<endl;
}
/*
Runtime: 4 ms, faster than 83.49% of C++ online submissions for String to Integer (atoi).
Memory Usage: 8.5 MB, less than 52.24% of C++ online submissions for String to Integer (atoi).
space:O(1)
time:O(str.length())
*/
