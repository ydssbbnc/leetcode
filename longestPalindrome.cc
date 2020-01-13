#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
  static  string longestPalindrome(string& s) {
        int p1=0,q1=s.length()-1,left=0,end=q1,p=0,q=end,max=1;
        if((end+1)<1||(end+1)>1000)
            return "";
        while((end-p1+1)>max){
            while(s[p]!=s[q])--q;
            if((q-p+1)<=max){
                p=++p1;q=q1=end;
            }else{
                q1=q;
                while(s[p]==s[q]&&p<q){
                    ++p;--q;
                }
                if(p>=q&&(q1-p1+1)>max){
                    max=q1-p1+1;left=p1++;p=p1;q=q1=end;
                }else if((q1-p1+1)<max){
                    p=p1++;q=q1=end;
                }else{
                    q=--q1;p=p1;
                }
            }
        }
        return s.substr(left,max);
    }
};
int main(){
  string s("acabcdefedcb");
  cout<<s<<endl;
  string res=Solution::longestPalindrome(s);
  cout<<"result: "<<res<<endl;
}
/*Runtime: 188 ms, faster than 23.83% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 8.9 MB, less than 69.65% of C++ online submissions for Longest Palindromic Substring.
*/
