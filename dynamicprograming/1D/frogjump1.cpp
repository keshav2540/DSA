#include <bits/stdc++.h>
using namespace std;
int minimumenergy(vector<int>nums,int index){ //track index
    if(index==0) return 0;
    int left=minimumenergy(nums,index-1)+abs(nums[index]-nums[index-1]);
     int right=INT32_MAX;
  if(index>1){  right=minimumenergy(nums,index-2)+abs(nums[index]-nums[index-2]);}
    return min(left,right);
}
//memorization
int minimumenergy(vector<int>nums,int index,vector<int>&dp){ //track index
    dp[0]=0;
    if(dp[index]!=-1) return dp[index];
    int left=minimumenergy(nums,index-1)+abs(nums[index]-nums[index-1]);
     int right=INT32_MAX;
  if(index>1){  right=minimumenergy(nums,index-2)+abs(nums[index]-nums[index-2]);}
    return dp[index]=min(left,right);
}
// tabulation botom to up
int minimumenergy2(vector<int>nums,int index,vector<int>&dp){ //track index
    dp[0]=0;
    for(int i=1;i<=index;i++){
    int left=dp[i-1]+abs(nums[i]-nums[i-1]);
     int right=INT32_MAX;
    if(i>1)right=dp[i-2]+abs(nums[i]-nums[i-2]);
     dp[i]=min(left,right);
}
    return dp[index];
}

int main() {
vector<int>nums={10,20,30,10};//energy reqire according to diff betwwen energy
vector<int>dp(nums.size()+1,-1);
cout<<minimumenergy(nums,3,dp);
    return 0;
}