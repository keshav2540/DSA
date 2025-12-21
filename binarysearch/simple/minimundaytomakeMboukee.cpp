#include <bits/stdc++.h>
using namespace std;
 bool bloumed(vector<int>nums,int mid,int nofbooke,int flowerin){
    int count=0;
    int numbooke=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=mid) count++;
        else{
            if(count>=flowerin) numbooke++;
            count=0;
        }}
         if(count>=flowerin) numbooke++;
         if(nofbooke<=numbooke) return true;
         return false;
        
}

int minimumdaytomakebooke(vector<int>nums, int nofbooke,int flowerin){
    if(nums.size()<(nofbooke*flowerin)) return -1;
    
    int n=nums.size();
    int low=INT32_MAX;
    int high=INT32_MIN;
    for(int i=0;i<n;i++){
        low=min(low,nums[i]);
        high=max(high,nums[i]);
    }
    int ans=-1;
     while(low<=high){
        int mid=low+(high-low)/2;
        if(bloumed(nums,mid,nofbooke,flowerin)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;     
        }
     } return ans;
}
int main() {
    vector<int>nums={7,7,7,7,13,11,12,7};
    int nofbooke=2;
    int flowerin=3;
    cout<<minimumdaytomakebooke(nums,nofbooke,flowerin);
    return 0;
}

