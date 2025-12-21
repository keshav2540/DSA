#include <bits/stdc++.h>
using namespace std;
bool ispossible(vector<int>nums,int mid,int threshold){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=ceil((double)nums[i]/(double)mid);
    }
    if(sum<=threshold) return true;
    else return false;
         
}

int smallestD(vector<int>nums, int threshold){
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
        if(ispossible(nums,mid,threshold)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;     
        }
     } return ans;
}
int main() {
    vector<int>nums={1,2,5,9};
    int threshold=6;
    cout<<smallestD(nums,threshold);
    return 0;
}