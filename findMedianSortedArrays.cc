/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
  static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int s1=0,m=nums1.size(),n=nums2.size(),s2=0,e1=m-1,e2=n-1,left=0,x1=-1,x2=-1;
    vector<bool>tag1{false,false},tag2{false,false};
    if(m==0&&n==0)return -1;
    if(m==0){
      if(n%2==0)
	return static_cast<double>(nums2[n/2-1]+nums2[n/2])/2;
      return static_cast<double>(nums2[n/2]);
    }
    if(n==0){
      if(m%2==0)
	return static_cast<double>(nums1[m/2-1]+nums1[m/2])/2;
      return static_cast<double>(nums1[m/2]);
    }
    if(n==1&&m==1)
          return static_cast<double>(nums1[0]+nums2[0])/2;
    while(left!=(m+n-1)/2){
      e1=m-1;e2=n-1;
      if(s1>e1){
	s2=(m+n-1)/2+s2-left-1;
	tag2[0]=true;
	left=(m+n-1)/2;
	break;
      }
      if(s2>e2){
	s1=(m+n-1)/2-left+s1-1;
	left=(m+n-1)/2;
	tag1[0]=true;
	break;
      }
      while(nums1[s1]<nums2[(s2+e2)/2]&&e2>=s2)
	e2=(s2+e2)/2-1;
      if(e2>=s2){
	if((left+(s2+e2)/2-s2+1)<(m+n-1)/2){
	  left+=((s2+e2)/2-s2+1);
	  s2=(s2+e2)/2+1;
	  tag2[1]=true;
	}else{
	  s2=(m+n-1)/2-left+s2-1;
	  tag2[0]=true;
	  left=(m+n-1)/2;
	}
      }else{
	while(nums1[(s1+e1)/2]>nums2[s2]&&e1>=s1)
	  e1=(s1+e1)/2-1;
	if(e1>=s1){
	  if((left+(s1+e1)/2-s1+1)<(m+n-1)/2){
	    left+=((s1+e1)/2-s1+1);
	    s1=(s1+e1)/2+1;
	    tag1[1]=true;
	  }else{
	    s1=(m+n-1)/2-left+s1-1;
	    tag1[0]=true;
	    left=(m+n-1)/2;
	  }
	}
      }
    }
    cout<<"tag1[0]: "<<tag1[0]<<"\ttag1[1]: "<<tag1[1]<<endl;
    cout<<"tag2[0]: "<<tag2[0]<<"\ttag2[1]: "<<tag2[1]<<endl;
    if(tag1[0])x1=s1+1;
    else if(tag1[1])x1=s1;
    else ++x1;
    if(tag2[0])x2=s2+1;
    else if(tag2[1])x2=s2;
    else ++x2;
    cout<<"x1: "<<x1<<"\tx2: "<<x2<<endl<<"s1: "<<s1<<"\ts2: "<<s2<<endl<<"left: "<<left<<endl;;
    if((m+n)%2!=0){
      if(x1>=nums1.size())
	return nums2[x2];
      if(x2>=nums2.size())
	return nums1[x1];
      return nums1[x1]>nums2[x2]?nums2[x2]:nums1[x1];
    }else{
      if(x1>(nums1.size()-1))
	return (static_cast<double>(nums2[x2]+nums2[x2+1]))/2;
      if(x2>(nums2.size()-1))
	return (static_cast<double>(nums1[x1]+nums1[x1+1]))/2;
      int min1,min2;
      if(x1==(nums1.size()-1)){
	if(nums1[x1]<nums2[x2]){
	  min1=nums1[x1];
	  min2=nums2[x2];
	}
	else{
	  min1=nums2[x2];
	  if(nums1[x1]<nums2[x2+1])
	    min2=nums1[x1];
	  else
	    min2=nums2[x2+1];
	}
	cout<<"min1: "<<min1<<endl<<"min2: "<<min2<<endl;
	return static_cast<double>(min1+min2)/2;
      }
      if(x2==(nums2.size()-1)){
	if(nums2[x2]<nums1[x1]){
	  min1=nums2[x2];
	  min2=nums1[x1];
	}
	else{
	  min1=nums1[x1];
	  if(nums2[x2]<nums1[x1+1])
	    min2=nums2[x2];
	  else
	    min2=nums1[x1+1];
	}
	cout<<"min1: "<<min1<<endl<<"min2: "<<min2<<endl;
	return static_cast<double>(min1+min2)/2;
      }
      if(nums1[x1]<nums2[x2]){
	min1=nums1[x1];
	if(nums1[x1+1]<nums2[x2])
	  min2=nums1[x1+1];
	else
	  min2=nums2[x2];
      }
      else{
	min1=nums2[x2];
	if(nums2[x2+1]<nums1[x1])
	  min2=nums2[x2+1];
	else
	  min2=nums1[x1];
      }
      cout<<"min1: "<<min1<<"\tmin2: "<<min2<<endl;
      return static_cast<double>(min1+min2)/2;
    }
  }
};
int main(){
  vector<int>v1;
  vector<int>v2;
  int t;
  cout<<"initialize v1(end with -1): ";
  while((cin>>t)&&t!=-1)
    v1.push_back(t);
  cout<<"initialize v2(end with -1): ";
  while((cin>>t)&&t!=-1)
    v2.push_back(t);  
  auto res=Solution::findMedianSortedArrays(v1,v2) ;
  cout<<"result: "  <<res<<endl;
}
/*
Runtime: 40 ms, faster than 5.79% of C++ online submissions for Median of Two Sorted Arrays.
Memory Usage: 9.9 MB, less than 47.42% of C++ online submissions for Median of Two Sorted Arrays.
*/
