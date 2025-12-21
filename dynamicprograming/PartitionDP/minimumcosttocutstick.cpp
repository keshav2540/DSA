#include <bits/stdc++.h>
using namespace std;
int helper(int i,int j,vector<int>&arr){
    if(i>j) return 0;
    int mini=1e9; 
    for(int k=i;k<=j;k++){
        int cost=arr[j+1]-arr[i-1]+helper(i,k-1,arr)+helper(k+1,j,arr);
        mini=min(mini,cost);
    } return mini;
    }
 int helper2(int n,vector<int>&arr,vector<vector<int>>&dp){
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j)continue;
            int mini=1e9;
            for(int k=i;k<=j;k++){
                  int cost=arr[j+1]-arr[i-1]+dp[i][k-1]+dp[k+1][j];
              mini=min(mini,cost);
             }  
              dp[i][j]=mini;
            }
        } return dp[1][n];
    }  
int minimumcost(int length,vector<int>&arr){
     int n=arr.size();
    arr.push_back(length);
    arr.insert(arr.begin(),0);
    sort(arr.begin(),arr.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    return helper2(n,arr,dp);
}
int main() {
 vector<int>arr={1,3,4,5};
 cout<<minimumcost(7,arr);
    return 0;
}