#include<vector>
#include<string>
#include<iostream>
#define N 8
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>mark;
        vector<string>item;
        vector<vector<string>>result;      
        for(int i=0;i<n;++i){
            vector<int>v;
            for(int j=0;j<n;++j){
                v.push_back(0);
            }
            mark.push_back(v);
            item.push_back("");
            item[i]+=string(n,'.');
        }
        generate(0,n,item,result,mark);
        return result;
    }
private:
  static const char dx[];
  static const char dy[];
    void put_down_a_queen(int x,
                         int y,
                         vector<vector<int>>&mark){
        mark[x][y]=1;
        for(int i=1;i<mark.size();++i){
            for(int j=0;j<8;++j){
                int new_x=x+i*dx[j];
                int new_y=y+i*dy[j];
                if(new_x>=0&&
                  new_x<mark.size()&&
                  new_y>=0&&
                  new_y<mark.size())
                    mark[new_x][new_y]=1;
            }
        }
    }
    void generate(int k,
                  int n,
                 vector<string>&item,
                 vector<vector<string>>&result,
                 vector<vector<int>>&mark){
        if(k==n){
            result.push_back(item);
            return;
        }
        for(int i=0;i<mark.size();++i){
            if(mark[k][i]==0){
                auto mark_copy=mark;
                item[k][i]='Q';
                put_down_a_queen(k,i,mark);
                generate(k+1,n,item,result,mark);
                mark=mark_copy;
                item[k][i]='.';
            }
        }
    }
};
 const char Solution::dx[]={
			   -1,1,0,0,1,1,-1,-1
 };
const char Solution::dy[]={
			  0,0,-1,1,1,-1,-1,1
};
int main(int argc,char**argv){
  Solution s1;
  cout<<"input n:\n";
  int in;
  cin>>in;
  auto result=s1.solveNQueens(in);
  cout<<"result:\n";
  cout<<"\n===========================\n";
  for(auto const&e:result){
    for(auto const&e1:e)
      cout<<e1<<endl;
  cout<<"\n===========================\n";
  }
}
/*time:O(n)
space:O(n)
Runtime: 40 ms, faster than 15.72% of C++ online submissions for N-Queens.
Memory Usage: 20.7 MB, less than 6.25% of C++ online submissions for N-Queens.
*/

