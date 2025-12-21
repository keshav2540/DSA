//frog can jump to 1 to k poisitions
#include <bits/stdc++.h>
using namespace std;
int minimumenergy(vector<int>nums,int index,int k){ //track index
    if(index==0) return 0;
    int minimum=INT_MAX;
    int jump;
    for(int i=1;i<=k;i++)
{
    if(index>=i){jump = minimumenergy(nums,index-i,k)+abs(nums[index]-nums[index-i]);}
 else break;
  minimum=min(minimum,jump);
} return  minimum;
}

//memorization
int minimumenergy3(vector<int>&nums,int index,vector<int>&dp,int k){ //track index
    dp[0]=0;
    if(dp[index]!=-1) return dp[index];
    int minimum=INT_MAX;
   for(int i=1;i<=k;i++)
{
    if(index>=i){int jump =minimumenergy3(nums,index-i,dp,k) +abs(nums[index]-nums[index-i]);minimum=min(minimum,jump);}
 else break;
} return dp[index]=minimum;
}
// tabulation botom to up
int minimumenergy2(vector<int>&nums,int index,vector<int>&dp,int k){ //track index
    dp[0]=0;
      int minimum=INT_MAX;
    for(int i=1;i<=index;i++){
      for(int i=1;i<=k;i++)
{
    if(index>=i){int jump =minimumenergy3(nums,index-i,dp,k) +abs(nums[index]-nums[index-i]);minimum=min(minimum,jump);}
 else break;
} dp[index]=minimum;
}
  return dp[index];
}

int main() {
vector<int>nums={10,20,30,10,50, 40, 50};//energy reqire according to diff betwwen energy
vector<int>dp(nums.size()+1,-1);
cout<<minimumenergy2(nums,6,dp,4);
    return 0;
}