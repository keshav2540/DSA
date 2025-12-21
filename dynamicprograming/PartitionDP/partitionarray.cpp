#include <bits/stdc++.h>
using namespace std;
int helper(int i,vector<int>arr,int k,int n){
    if(i==n) return 0;
   int len=0;
   int maxi=0;
   int ans=0;
   int loopend=min((i+k),n);
   for(int j=i;j<loopend;j++){
   len++;
   maxi=max(maxi,arr[j]);
   int sum=maxi*len+helper(j+1,arr,k,n);
   ans=max(ans,sum);
   } return ans;}

int helper2(int n,vector<int>arr,int k){
    vector<int>dp(n+1,0);
    for(int i=n-1;i>=0;i--){
        int len=0;
   int maxi=0;
   int ans=0;
   int loopend=min((i+k),n);
   for(int j=i;j<loopend;j++){
   len++;
   maxi=max(maxi,arr[j]);
   int sum=maxi*len+helper(j+1,arr,k,n);
   ans=max(ans,sum);
   }  dp[i]=ans;
}return dp[0];
    }
int partitionsum_max(vector<int>arr,int k){
    // return helper(0,arr,k,arr.size());
    return helper2(arr.size(),arr,k);
}

int main() {
   vector<int>arr={1,15,7,9,2,5,10};
    cout<<partitionsum_max(arr,3);
    return 0;
}