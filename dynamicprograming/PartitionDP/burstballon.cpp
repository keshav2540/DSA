#include <bits/stdc++.h>
using namespace std;
int helper(int i,int j,vector<int>&arr){
    if(i>j) return 0;
    int maxxi=0; 
    for(int k=i;k<=j;k++){
     int cost=arr[j+1]*arr[k]*arr[i-1]+helper(i,k-1,arr)+helper(k+1,j,arr);
    maxxi=max(maxxi,cost);
    } return maxxi;
    }
 int helper2(int n,vector<int>&arr,vector<vector<int>>&dp){
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j)continue;
            int maxxi=0;
            for(int k=i;k<=j;k++){
                  int cost=arr[j+1]*arr[k]*arr[i-1]+dp[i][k-1]+dp[k+1][j];
              maxxi=max(maxxi,cost);
             }  
              dp[i][j]=maxxi;
            }
        } return dp[1][n];
    }  
int minimumcoin(vector<int>&arr){
     int n=arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(),1);
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    return helper(1,n,arr);
}
int main() {
 vector<int>arr={3,1,5,8};
 cout<<minimumcoin(arr);
    return 0;
}