#include <bits/stdc++.h>
using namespace std;
int helper(int i,int j,vector<int>&arr){
    if(i==j) return 0;
    int mini=1e9;
    for(int k=i;k<j;k++){
        int step=arr[i-1]*arr[k]*arr[j]+helper(i,k,arr)+helper(k+1,j,arr);
        if(mini>step) mini=step;
    }
    return mini;
}
int helper1(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
    if(i==j) return 0;
    int mini=1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    for(int k=i;k<j;k++){
        int step=arr[i-1]*arr[k]*arr[j]+helper(i,k,arr)+helper(k+1,j,arr);
        if(mini>step) mini=step;
    }
    return dp[i][j]=mini;
}
int helper2(int n,vector<int>&arr,vector<vector<int>>&dp){
    for(int i=0;i<n;i++)dp[i][i]=0;
    int mini=1e9;
    for(int i=n-1;i>=1;i--){
        for(int j=n-1;j>=i;j--){
          int mini=1e9;
           for(int k=i;k<j;k++){
         int step=arr[i-1]*arr[k]*arr[j]+helper(i,k,arr)+helper(k+1,j,arr);
          if(mini>step) mini=step;
          }
        dp[i][j]=mini; 
        }
    } return dp[1][n-1];
}
int numofopration(vector<int>arr){// mutipicationm
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    // return helper1(1,n-1,arr,dp);
    return helper2(n,arr,dp);
}
int main() {
// vector<int>matrixsize={10,20,30,40,50};
vector<int>matrixsize={10,30,5,60};
cout<<numofopration(matrixsize);
    return 0;
}