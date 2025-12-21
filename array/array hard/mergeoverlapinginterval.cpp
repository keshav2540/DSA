#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&nums,int start, int mid,int end){
     vector<int>temp;
     int i=start,j=mid+1;
     while(i<=mid && j<=end){
            if(nums[i]>nums[j]){
                 temp.push_back(nums[j++]);
            }
            else{
                temp.push_back(nums[i++]);
            }
         }
      while(i<=mid) temp.push_back(nums[i++]);
      while(j<=end) temp.push_back(nums[j++]);
      for(int i:temp) nums[start++]=i;    
}
 int countpair(vector<int>nums, int start, int mid,int end){
    int k=mid+1,count =0,totalcount=0;
    for(int i=start;i<=mid;i++){
        while(i<=mid && nums[i]>(2*nums[k])&&k<=end) k++;
        totalcount+=k-(mid+1);
    }
     return totalcount;
 }


 int mergesort( vector<int>&nums,int start,int end){
    int count=0;
    if(start==end) return count;
     int mid=start+(end-start)/2;
   count+= mergesort(nums,start,mid);
   count+= mergesort(nums,mid+1,end);
   count+=countpair(nums,start,mid ,end);
    merge(nums,start,mid,end);
    return count;
 }

int main() {
    vector<int>nums={40,25,19,12,9,6,2};
    int n=nums.size();
    cout<<mergesort(nums,0,n-1)<<endl;
    for(int i:nums) cout<<i<<endl;
    return 0;
}