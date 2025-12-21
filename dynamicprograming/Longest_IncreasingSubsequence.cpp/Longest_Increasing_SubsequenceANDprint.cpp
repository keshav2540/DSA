#include <bits/stdc++.h>
using namespace std;
int f(int ind,int prev ,int n,vector<int>&arr){
  if(ind==n)return  0;
  int not_take=f(ind+1,prev,n,arr);
  int take=0;
  if(prev==-1||arr[ind]>arr[prev]) take=1+f(ind+1,ind,n,arr);
  int len=max(take,not_take);
  return len;
}
int f1(int ind,int prev,int n,vector<int>&arr,vector<vector<int>>&dp){
  if(ind==n)return 0;
  if(dp[ind][prev+1]!=0)return dp[ind][prev+1];
  int not_take=f1(ind+1,prev,n,arr,dp);
  int take=0;
  if(prev==-1||arr[ind]>arr[prev]) take=1+f1(ind+1,ind,n,arr,dp);
  int len=max(take,not_take);
  return dp[ind][prev+1]=len;
}
int f2(int ind,int prev,int n,vector<int>&arr,vector<vector<int>>&dp){
    for(int ind=n-1;ind>=0;ind--){
        for(int prev=ind-1;prev>=-1;prev--){
            int not_take=dp[ind+1][prev+1];
            int take=0;
            if(prev==-1||arr[ind]>arr[prev]) take=1+dp[ind+1][ind+1];
            int len=max(take,not_take);
           dp[ind][prev+1]=len;
        }
    }return dp[0][-1+1];
}
int f3(int ind,int prev,int n,vector<int>&arr,vector<vector<int>>&dp){
    vector<int>next(n+1,0),curr(n+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int prev=ind-1;prev>=-1;prev--){
            int not_take=next[prev+1];
            int take=0;
            if(prev==-1||arr[ind]>arr[prev]) take=1+next[ind+1];
            int len=max(take,not_take);
           curr[prev+1]=len;
        }next=curr;
    }return next[-1+1];
}
int f_usingalgo(int ind,int prev ,int n,vector<int>&arr){
    int lcs=0;
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
            lcs=max(lcs,dp[i]);
        }
    } return lcs;
}
int f_usingalgo_PRINT(int ind,int prev ,int n,vector<int>&arr){
    int lcs=0;
    vector<int>dp(n,1);
    vector<int>hash(n,1);
     int lastindex=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]&& dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                lcs=dp[i];
                hash[i]=j;
                lastindex=i;
            }
            lcs=max(lcs,dp[i]);
        }
    }
    vector<int>temp;
    temp.push_back(arr[lastindex]);
    while(temp.size()!=lcs){
        lastindex=hash[lastindex];
        temp.push_back(arr[lastindex]);
    }
    reverse(temp.begin(),temp.end());
    for(int i:temp) cout<<i<<" ";
    cout<<endl;
     return lcs;
}
 int lcs(vector<int>&arr){
 int n=arr.size();
 vector<vector<int>>dp(n+1,vector<int>(n+1,0));
 return f_usingalgo_PRINT(0,-1,n,arr);
}
int main() {
vector<int>arr={5,4,11,1,16,0};
vector<int>arr1={1,2,2};
vector<int>arr2={10,9,2,5,3,7,101,18};
cout<<lcs(arr)<<endl;
cout<<lcs(arr1)<<endl;
cout<<lcs(arr2)<<endl;
    return 0;
}