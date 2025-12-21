#include <bits/stdc++.h>
using namespace std;
int helper(int idx,int target,vector<int>&arr){
    if(idx==0){//think what happend when target is 0,we not write this case hows it work
      if(target%arr[0]==0){
        return target/arr[0];
      } return INT32_MAX;
       }
    int not_take=0+helper(idx-1,target,arr);
    int take=INT32_MAX;
    if(target>=arr[idx]) take=1+helper(idx,target-arr[idx],arr);
    return min (take,not_take);
}
int helper2(int idx,int target,vector<int>&arr,vector<vector<int>>&dp){//memorizzation use in overlapping 
    if(idx==0){
        if(target%arr[0]==0){
        return target/arr[0];
      } return INT32_MAX;
    }
    if(dp[idx][target]!=0) return dp[idx][target];
    int not_take=0+helper2(idx-1,target,arr,dp);
    int take=INT32_MAX;
    if(target>=arr[idx]) take=1+helper2(idx,target-arr[idx],arr,dp);
    return dp[idx][target]=min(take,not_take);
}
int helper3(int idx,int target,vector<int>&arr,vector<vector<int>>&dp){
    for(int i=0;i<=target;i++){
        if(i%arr[0]==0) dp[0][i]=i/arr[0];
        else dp[0][i]=1e9;
    }
    for(int i=1;i<=idx;i++){
        for(int k=0;k<=target;k++){
    int not_take=0+dp[i-1][k];
    int take=1e9;
    if(k>=arr[i]) take=1+dp[i][k-arr[i]];
     dp[i][k]=min(take,not_take);
        }
    }return dp[idx][target];
}
int helperspaceoptimize(int idx,int target,vector<int>&arr,vector<vector<int>>&dp){
    vector<int>prev(target+1,0),curr(target+1,0);
    for(int i=0;i<=target;i++){
        if(i%arr[0]==0) prev[i]=i/arr[0];
        else prev[i]=1e9;
    }
    for(int i=1;i<=idx;i++){
        for(int k=0;k<=target;k++){
    int not_take=0+prev[k];
    int take=1e9;
    if(k>=arr[i]) take=1+curr[k-arr[i]];
     curr[k]=min(take,not_take);
        }prev=curr;
    }return prev[target];
}
int minimumcoin(int target,vector<int>&arr){
    int idx=arr.size();
    vector<vector<int>>dp(idx,vector<int>(target+1,0));
    return helperspaceoptimize(idx-1,target,arr,dp);
}
int main() {
vector<int>arr={1,2,3};//not use greedy because uniformity not have in data
cout<<minimumcoin(7,arr)<<endl;
cout<<minimumcoin(3,arr)<<endl;
cout<<minimumcoin(4,arr)<<endl;
cout<<minimumcoin(9,arr)<<endl;
cout<<minimumcoin(2,arr)<<endl;
    return 0;
}