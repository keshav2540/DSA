#include <bits/stdc++.h>
using namespace std;
int merge(vector<int>&nums,int start, int mid,int end){
     vector<int>temp;
     int i=start,j=mid+1,count=0;
     while(i<=mid && j<=end){
            if(nums[i]>nums[j]){
                 temp.push_back(nums[j++]);
                 count+=(mid-i+1);
            }
            else{
                temp.push_back(nums[i++]);
            }
         }
      while(i<=mid) temp.push_back(nums[i++]);
      while(j<=end) temp.push_back(nums[j++]);
      for(int i:temp) nums[start++]=i;    
      return count;
}
 
 int mergesort( vector<int>&nums,int start,int end){
    int count=0;
    if(start==end) return count;
     int mid=start+(end-start)/2;
   count+= mergesort(nums,start,mid);
   count+= mergesort(nums,mid+1,end);
   count+=merge(nums,start,mid,end);
    return count;
 }

int main() {
    vector<int>nums={5,3,2,4,1};
    int n=nums.size();
    cout<<mergesort(nums,0,n-1)<<endl;
    for(int i:nums) cout<<i<<endl;
    return 0;
}