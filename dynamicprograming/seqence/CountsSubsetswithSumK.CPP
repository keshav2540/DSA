#include <bits/stdc++.h>
using namespace std;
int helper(int n,int target,vector<int>&arr){
    if(target==0) return 1;
    if(n==0)return arr[0]==target;
    return (helper(n-1,target,arr)+(target>=arr[n]?helper(n-1,target-arr[n],arr):0));
}
int helper2(int n,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0) return 1;
    if(n==0)return arr[0]==target;
    if(dp[n][target]!=0) return dp[n][target];
    return  dp[n][target]=(helper2(n-1,target,arr,dp)+(target>=arr[n]?helper2(n-1,target-arr[n],arr,dp):0));
}
int helper3(int n,int target,vector<int>&arr,vector<vector<int>>&dp){
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
       dp[0][arr[0]]=1;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=target;k++){
            dp[i][k]=((dp[i-1][k])+(k>=arr[i]?dp[i-1][k-arr[i]]:0));
        }
    } return dp[n][target];
}
int helperSpaceOptimization(int n,int target,vector<int>&arr,vector<vector<int>>&dp){
    vector<int>prev(1+target,0),curr(1+target,0);
        prev[0]=curr[0]=1;
    prev[arr[0]]=1;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=target;k++){
            curr[k]=((prev[k])+(k>=arr[i]?prev[k-arr[i]]:0));
        }prev=curr;
    } return prev[target];
}
int SumIspossible(vector<int>&arr,int target){
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    return helper3(n-1,target,arr,dp);
}
int main() {
    vector<int>arr={1,2,2,3};// it give wrong ans on 0,0,1 and target=1; in this problem not consider 0
     cout<<SumIspossible(arr,3);
    return 0;
}