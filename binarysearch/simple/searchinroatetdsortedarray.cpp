#include <bits/stdc++.h>
using namespace std;
int bsarr1(vector<int>nums,int target){
    int st=0,end=nums.size()-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<=nums[st]){// right sorted
            if(target>nums[mid] && target<=nums[end]) st=mid+1;
            else end=mid-1;
        }
        else{
            if(target<nums[mid]&& target>nums[st]) end=mid-1;
            else st=mid+1;
        }
    }
 return -1;
}
int bsarr2(vector<int>nums,int target){
    int st=0,end=nums.size()-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]==nums[st] && nums[mid]==nums[end]){st++;end--; continue;}
        else if(nums[mid]<=nums[st]){// right sorted
            if(target>nums[mid] && target<=nums[end]) st=mid+1;
            else end=mid-1;
        }
        else{
            if(target<nums[mid]&& target>nums[st]) end=mid-1;
            else st=mid+1;
        }
    }
      
 return -1;
}

int main() {
    vector<int>nums={7,8,9,1,2,3,4,5,6};
    int target=6;
    cout<<bsarr1(nums,target)<<endl;
    vector<int>nums1={3,1,2,3,3,3,3};
    cout<<bsarr1(nums1,2)<<endl;
    cout<<bsarr2(nums1,2);
    return 0;
}