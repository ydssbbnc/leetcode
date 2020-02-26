/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/
#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int>s;
        string result="";
        for(int i=0;i<num.length();++i){
            int number=num[i]-'0';
            while(s.size()&&s.back()>number&&k>0){
                s.pop_back();
                --k;
            }
            if(number||s.size()){
                s.push_back(number);
            }
        }
        while(s.size()&&k>0){
            s.pop_back();
            --k;
        }
        for(int i=0;i<s.size();++i){
            result+=('0'+s[i]);
        }
        if(result=="")
            return "0";
        return result;
    }
};
int main(int argc,char**argv){
  string num=argv[1];
  int k=atoi(argv[2]);
  Solution s1;
  cout<<"result: "<<  s1.removeKdigits(num,k)<<endl;
}
/*
Runtime: 8 ms, faster than 57.98% of C++ online submissions for Remove K Digits.
Memory Usage: 9.7 MB, less than 9.09% of C++ online submissions for Remove K Digits.
*/
