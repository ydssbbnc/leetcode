/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct GraphNode{
  int label;
  vector<GraphNode*>neighbors;
    GraphNode(int x):label(x){}
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<GraphNode*>graph;
        vector<int>degree;
        for(int i=0;i<numCourses;++i){
            degree.push_back(0);
            graph.push_back(new GraphNode(i));
        }
        for(int i=0;i<prerequisites.size();++i){
            GraphNode*begin=graph[prerequisites[i].back()];
            GraphNode*end=graph[prerequisites[i].front()];
            begin->neighbors.push_back(end);
            ++degree[prerequisites[i].front()];
        }
        queue<GraphNode*>Q;
        for(int i=0;i<numCourses;++i){
            if(!degree[i]){
                Q.push(graph[i]);
            }
        }
        while(!Q.empty()){
            GraphNode*node=Q.front();
            Q.pop();
            for(int i=0;i<node->neighbors.size();++i)   {
                --degree[node->neighbors[i]->label]       ;
                if(!degree[node->neighbors[i]->label]){
                    Q.push(node->neighbors[i]);
                }
            }
        }
        for(int i=0;i<graph.size();++i)
            delete graph[i];
        for(int i=0;i<degree.size();++i)
            if(degree[i]){
                return false;       
            }
        return true;
    }
};
int main(){
  Solution s1;
  vector<vector<int>>pre{
			 {1,0},
			 {5,7},
			 {4,3},
			 {3,5}
  };
  cout<<(s1.canFinish(6,pre))<<endl;
}
/*
Runtime: 20 ms, faster than 87.85% of C++ online submissions for Course Schedule.
Memory Usage: 12.8 MB, less than 96.36% of C++ online submissions for Course Schedule.
time:O(e+n)
space:O(n)
*/
