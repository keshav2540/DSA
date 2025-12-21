// memoriation is apply when overlapping in occur 
// when data is not uniform we cannot use greedy algo in this
#include <bits/stdc++.h>
using namespace std;
int helper(int idx,int maxwet,vector<int>&wt,vector<int>&wetval){
    if(idx==0){
        if(maxwet>=wt[idx]) return wetval[0];
        return 0;
    }
    int not_take=0+helper(idx-1,maxwet,wt,wetval);
    int take=INT32_MIN;
    if(maxwet>=wt[idx]) take=wetval[idx]+helper(idx-1,maxwet-wt[idx],wt,wetval);
    return max(take,not_take);
}
int helper2(int idx,int maxwet,vector<int>&wt,vector<int>&wetval,vector<vector<int>>&dp){
    if(idx==0){
        if(maxwet>=wt[idx]) return wetval[0];
        return 0;
    }
    if(dp[idx][maxwet]!=0) return dp[idx][maxwet];
    int not_take=0+helper2(idx-1,maxwet,wt,wetval,dp);
    int take=INT32_MIN;
    if(maxwet>=wt[idx]) take=wetval[idx]+helper2(idx-1,maxwet-wt[idx],wt,wetval,dp);
    return dp[idx][maxwet]=max(take,not_take);
}
int helper3(int idx,int maxwet,vector<int>&wt,vector<int>&wetval,vector<vector<int>>&dp){
        for(int i=wt[0];i<=maxwet;i++){
            dp[0][i]=wetval[0];
        }
        for(int i=1;i<=idx;i++){
        for(int target=0;target<=maxwet;target++){
        int not_take=0+dp[i-1][target];
        int take=INT32_MIN;
        if(target>=wt[i]) take=wetval[i]+dp[i-1][target-wt[i]];
        dp[i][target] = max(take,not_take);
        }
        } return dp[idx][maxwet];
}
int helperspaceoptimize(int idx,int maxwet,vector<int>&wt,vector<int>&wetval,vector<vector<int>>&dp){
    vector<int>prev(maxwet+1,0),curr(maxwet+1,0);
        for(int i=wt[0];i<=maxwet;i++){
            prev[i]=wetval[0];
        }
        for(int i=1;i<=idx;i++){
        for(int target=0;target<=maxwet;target++){
        int not_take=0+prev[target];
        int take=INT32_MIN;
        if(target>=wt[i]) take=wetval[i]+prev[target-wt[i]];
        curr[target] = max(take,not_take);
        }prev=curr;
        } return prev[maxwet];
}
int helperspaceoptimizeultra(int idx,int maxwet,vector<int>&wt,vector<int>&wetval,vector<vector<int>>&dp){
    vector<int>prev(maxwet+1,0);//wow
        for(int i=wt[0];i<=maxwet;i++){
            prev[i]=wetval[0];
        }
        for(int i=1;i<=idx;i++){
        for(int target=maxwet;target>=0;target--){ //compare unbounded ksanap 
        int not_take=0+prev[target];
        int take=INT32_MIN;
        if(target>=wt[i]) take=wetval[i]+prev[target-wt[i]];
        prev[target] = max(take,not_take);
        }
        } return prev[maxwet];
}
int knapsack(int maxwet,vector<int>&wt,vector<int>&val){
     int idx=wt.size()-1;
     vector<vector<int>>dp(idx+1,vector<int>(maxwet+1,0));
     return helperspaceoptimizeultra(idx,maxwet,wt,val,dp);
}
int main() {
    vector<int>wt={3,4,5};
    vector<int>val={30,40,60};
    cout<<knapsack(8,wt,val)<<endl;
    cout<<knapsack(7,wt,val);
    return 0;
}