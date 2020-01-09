/*Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
  static int lengthOfLongestSubstring(string &s) {
    unordered_map<int,int>um;
    vector<int>ret;
    int t=0;
    for(int i=0,j=0;i<s.size();++i){
      for(j=i+1;j<s.size();++j){
	if(s[i]==s[j]){
	    um[i]=j;
	    break;	    
	}
      }
      if(j==s.size())
	um[i]=s.size();
    }
    for(int i=0;i<s.size();++i){
      t=um[i];
      for(int j=i+1;j<s.size();++j){
	if(um[j]<t)
	  t=um[j];
      }
      ret.push_back(t-i);
    }
    t=0;
    for(auto const &e:ret)
      if(t<e)
	t=e;
    return t;
  }
};
int main(){
  string s="abcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdsabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdabcasdfkxcm,vnzxmwqoewuryeuutopdkfhxklcmvcv;a'sdjfksdkfjskdfksdhjxbvjzflskdjfoiqwrtuiqwtospofsdjfksjfklsjdfknxdkgvnkzldfjksldjfksldfjasyhgfoweiqtryuweghtjndsmncfvfhajfnjsdbnvbcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdgdfsafasbbabcabcsdfafsadfasdgsdagggggggggggggaaaaaaaaafdsfsdafwetqeyhtrujyn ikhjfgdghgdsgdfsafasbb";
  cout<<Solution::lengthOfLongestSubstring(s)<<endl;
  return 0;
}
/*
this Solution is correctly executed on linux but Time Limit Exceeded on leetcode
*/
