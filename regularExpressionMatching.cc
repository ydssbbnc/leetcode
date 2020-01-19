#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
struct Solution{
  bool isMatch(const string& s,const string& p){
    int ls=s.size(),lp=p.size(),i=0,j=0;
    if(lp==0)return ls?false:true;
    if(ls==0){
      while(j<lp&&p[j]=='*')++j;
      return (j==lp)?true:false;
    }
    if(p[j]=='*'){
      while(j<lp&&p[j]=='*')++j;
    }
    if(j==lp)return false;
    char pc1,pc2;
    while(i<ls&&j<lp){
      while(i<ls&&j<lp&&s[i]==p[j]){
	++i;++j;
      }
      if(i<ls&&j<lp){
	if(!(p[j]=='*'||p[j]=='.'))return false; 
	if(p[j]=='*'){
	  while(j<lp&&p[j]=='*')++j;
	  for(pc1=s[i-1];i<ls&&s[i]==pc1;++i);
	}
	else{
	  if(j==(lp-2)&&p[lp-1]=='*')return true;
	  if(j<(lp-2)&&p[j+1]=='*'){
	    //do the hardest partial "  .*  "
	  }else{
	    ++i;++j;
	  }
	}
      }
    }
    if(i==ls&&j==lp)return true;
    if(i==ls){
      while(j<lp&&p[j]=='*')++j;
      return (j==lp)?true:false;
    }
    for(pc1=p[j-2];i<ls&&s[i]==pc1;++i);
    return (i==ls)?true:false; 
  }
};
int main(int argc,char**argv){
  string  p=(string(argv[2])=="0")?"":argv[2];
  string  s=(string(argv[1])=="0")?"":argv[1];
  cout<<"s = "<<s<<"\np = "<<p<<endl;
  Solution s1;
  auto res=s1.isMatch(s,p);
  cout<<"isMatch = "<<boolalpha<<res<<noboolalpha<<endl;
}
