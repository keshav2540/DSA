#include <bits/stdc++.h>
using namespace std;
int helper(int n,int target,vector<int>&arr){
    if(n==0){
        if(target==0 &&arr[0]==0)return 2;
        if(target==0||arr[0]==target) return 1;
        return 0;
    }
    return (helper(n-1,target,arr)+(target>=arr[n]?helper(n-1,target-arr[n],arr):0));
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
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    int count=0;
    return helper(n-1,target,arr);
    // for(int i=0;i<n;i++) if(arr[i]==0)count++;
    // return (count?pow(2,count):1*(helperSpaceOptimization(n-1,target,arr,dp)));
}
int main() {
    vector<int>arr={0,0,1};// it give wrong ans on 0,0,1 and target=1; in this problem not consider 0
    // we have two zero and have two option in one zero can take and not take in our set this mean one zero have 2 chance though have n zero chance is equal to 2^n these chance is multiply with all subset  give us ans at the end 
     cout<<SumIspossible(arr,1);
    return 0;
}