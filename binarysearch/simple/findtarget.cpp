#include <bits/stdc++.h>
using namespace std;
int  findtarget(vector<int>nums,int target){
    int n=nums.size();
    int st=0,end=n-1;
    while(st<=end){
         int mid=st+(end-st)/2;
         if(nums[mid]>target){
            end=mid-1;
         }
         else if(nums[mid]<target){
            st=mid+1;
         }
        else return mid;

    }
 return -1;
}

int recursive(vector<int>nums,int target,int start,int end){ 
    if(start<=end)
 {int mid=start+(end-start)/2;
 if(nums[mid]>target)  return recursive(nums,target,start,mid-1);
 else if(nums[mid]<target)  return recursive(nums,target,mid+1,end);
 else return mid;}
  return -1;}

int main() {
    vector<int>nums={3,4,6,7,9,12,16,17};
    cout<<recursive(nums,12,0,7);
    return 0;
}