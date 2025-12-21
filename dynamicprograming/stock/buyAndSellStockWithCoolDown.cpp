#include <bits/stdc++.h>
using namespace std;//buy and sell many times iterval is one of after sell
int helper(int idx,bool buy,vector<int>&arr){
    if(idx>=arr.size()) return 0;
    int profit=0;
    if(buy){
     profit=max(-arr[idx]+helper(idx+1,0,arr),helper(idx+1,1,arr));
    }
    else{
        profit=max(arr[idx]+helper(idx+2,1,arr),helper(idx+1,0,arr));
    }
    return profit;
}
int helper2(int idx,bool buy,vector<int>&arr,vector<vector<int>>&dp){
    if(idx>=arr.size()) return 0;
    if(dp[idx][buy]!=-1)return dp[idx][buy];
    int profit=0;
    if(buy){
     profit=max(-arr[idx]+helper2(idx+1,0,arr,dp),helper2(idx+1,1,arr,dp));
    }
    else{
        profit=max(arr[idx]+helper2(idx+2,1,arr,dp),helper2(idx+1,0,arr,dp));
    }
    return dp[idx][buy]=profit;
}
int helper3(int idx,bool buy,vector<int>&arr,vector<vector<int>>&dp){
    int n=arr.size();
    int idex=n-1;// no need to write because we use 0 base indexing
    for(int i=idex;i>=0;i--){ 
        for(int j=0;j<=buy;j++){
        int profit=0;
       if(j){
        profit=max(-arr[i]+dp[i+1][0],dp[i+1][1]);
       }
       else{
         profit=max(arr[i]+dp[i+2][1],dp[i+1][0]);
        }                    // modify dp size
     dp[i][j]=profit;
        }
        }
      return dp[idx][buy];
}
int helper4(int idx,bool buy,vector<int>&arr,vector<vector<int>>&dp){
    int n=arr.size();
    int idex=n-1;// no need to write because we use 0 base indexing
    for(int i=idex;i>=0;i--){ 
        dp[i][1]=max(-arr[i]+dp[i+1][0],dp[i+1][1]);
        dp[i][0] =max(arr[i]+dp[i+2][1],dp[i+1][0]);
                          // modify dp size
        }
      return dp[idx][buy];
}
int helper5(int idx,bool buy,vector<int>arr,vector<vector<int>>&dp){
      vector<int>ahead1(2,0),ahead2(2,0),curr(2,0);
    int n=arr.size();
    int idex=n-1;//no need to write base case 0 base indexsing
    for(int i=idex;i>=0;i--){
        curr[1]=max(-arr[i]+ahead1[0],ahead1[1]); // only two case not use loop write directly
        curr[0]=max(arr[i]+ahead2[1],ahead1[0]);
         ahead2=ahead1;
         ahead1=curr;}
      return ahead1[buy];
}
int maxprofitwithcooldownIterval(vector<int>&arr){
    vector<vector<int>>dp(arr.size()+2,vector<int>(2,0));
    return helper5(0,1,arr,dp);
}
int main() {
vector<int>arr={4,9,0,4,10};
vector<int>arr1={1,2,3,0,2};
cout<<maxprofitwithcooldownIterval(arr)<<endl;
cout<<maxprofitwithcooldownIterval(arr1)<<endl;
    return 0;
}