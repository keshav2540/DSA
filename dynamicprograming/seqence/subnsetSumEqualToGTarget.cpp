#include <bits/stdc++.h>
using namespace std;
bool helper(int n,int target,vector<int>&arr){
    if(target==0) return true;
    if(n==0)return arr[0]==target;
    return (helper(n-1,target,arr)||(target>=arr[n]?helper(n-1,target-arr[n],arr):false));
}
bool helper2(int n,int target,vector<int>&arr,vector<vector<bool>>&dp){
    if(target==0) return true;
    if(n==0)return arr[0]==target;
    if(dp[n][target]!=0) return dp[n][target];
    return  dp[n][target]=(helper2(n-1,target,arr,dp)|(target>=arr[n]?helper2(n-1,target-arr[n],arr,dp):false));
}
bool helper3(int n,int target,vector<int>&arr,vector<vector<bool>>&dp){
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=target;k++){
            dp[i][k]=((dp[i-1][k])|(k>=arr[i]?dp[i-1][k-arr[i]]:false));
        }
    } return dp[n][target];
}
bool helperSpaceOptimization(int n,int target,vector<int>&arr,vector<vector<bool>>&dp){
    vector<bool>prev(1+target,false),curr(1+target,false);
        prev[0]=curr[0]=true;
    prev[arr[0]]=true;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=target;k++){
            curr[k]=((prev[k])|(k>=arr[i]?prev[k-arr[i]]:false));
        }prev=curr;
    } return prev[target];
}
bool SumIspossible(vector<int>&arr,int target){
    int n=arr.size();
    vector<vector<bool>>dp(n,vector<bool>(target+1,0));
    return helperSpaceOptimization(n-1,target,arr,dp);

}
int main() {
    vector<int>arr={1,1,0,4};
     cout<<SumIspossible(arr,6);
    return 0;
}