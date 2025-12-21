#include <bits/stdc++.h>
using namespace std;// jump one and two step find how much way 
int countway(int stiars){ // its like fibonnaci using 0 base indexing
    if(stiars==0|| stiars==1)return 1;
    int left=countway(stiars-1);
    int right=countway(stiars-2);
    return  left+right;
}

// memoritaions
int countway2(int stiars,vector<int>&dp){ // its like fibonnaci using 0 base indexing
    if(stiars==0|| stiars==1)return 1;
    if(dp[stiars]!=-1) return  dp[stiars];
    int left=countway2(stiars-1,dp);
    int right=countway2(stiars-2,dp);
    return dp[stiars]=left+right;
}
//tabulaton;
int findcount(int n,vector<int>&dp){
         dp[1]=1;
         dp[0]=1; //tc=n sc=n 
         for(int i=2;i<=n;i++){
           dp[i]=dp[i-1]+dp[i-2];
         } return dp[n];  
}

int main() {
    int n=4;
    vector<int>dp(n+1,-1);
    cout<<findcount(n,dp);

    return 0;
}