#include <bits/stdc++.h>
using namespace std;
// normalrecusion
 int findfib(int n){ //tc=(2^n) sc=n
    if(n<=1) return n;
    return findfib(n-1)+findfib(n-2);
 }
//  memorization concept avoid calculate same fun multiple time
//  like we caculate findfib is multiple time
//using a map and list
int findf(int n,vector<int>&dp){
        if(n<=1)return dp[n]=n; //tc=n sc=2n 
        if(dp[n]!=-1)return dp[n];
        return dp[n]=findf(n-1,dp)+findf(n-2,dp);
}
//tabulation base case reqire
int find(int n,vector<int>&dp){
         dp[1]=1;
         dp[0]=0; //tc=n sc=n 
         for(int i=2;i<=n;i++){
           dp[i]=dp[i-1]+dp[i-2];
         } return dp[n];  
}
//optimize
int findop(int n){
         int prev=1;
         int secprev=0;
         int curr=0; //tc=n sc=0
         for(int i=2;i<=n;i++){
           curr=prev+secprev;
           secprev=prev;
           prev=curr;
         } return curr;  
}


int main() {
    int n=5;
    vector<int>dp(n+1,-1);
    cout<<findop(5);
    return 0;
}