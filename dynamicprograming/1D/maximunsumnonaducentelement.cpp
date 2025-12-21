#include <bits/stdc++.h>
using namespace std; // non aducent mean not contibeous i-1 and i+1 positions not exist
int findsum(vector<int>&nums,int index){
    if(index==0) return nums[0];
    if(index<0)return 0;
    int pick=nums[index]+findsum(nums,index-2);
    int notpick=findsum(nums,index-1);
     return max(pick,notpick);
}
// memorization
int findsum2(vector<int>&nums,int index,vector<int>&dp){
     if(index==0) return nums[0];
    if(index<0)return 0;
    if(dp[index]!=-1) return dp[index];
     int pick=nums[index]+findsum2(nums,index-2,dp);
    int notpick=findsum2(nums,index-1,dp);
     return dp[index]=max(pick,notpick);
}
//tabulation
int findsum3(vector<int>&nums,int index,vector<int>&dp){
    dp[0]=nums[0];
    for(int i=1;i<nums.size();i++){
    int pick=nums[i];
    if(i>1)pick+=dp[i-2];
    int notpick=dp[i-1];
      dp[i]=max(pick,notpick);
    } return dp[index];
}
// space optimize
int findsum4(vector<int>nums){
    int prev=nums[0];
    int sprev=0;
    int curr=0;
     for(int i=1;i<nums.size();i++){
    int pick=nums[i];
    if(i>1)pick+=sprev;
    int notpick=prev;
       curr=max(pick,notpick);
      sprev=prev;
      prev=curr;
    } return curr;
}

int main() {
    vector<int>nums={1,2,4};
    vector<int>dp(nums.size(),-1);
    cout<<findsum2(nums,nums.size()-1,dp);
    cout<<findsum4(nums);

    return 0;
}