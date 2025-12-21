// memoriation is apply when overlapping in occur 
// when data is not uniform we cannot use greedy algo in this
#include <bits/stdc++.h>
using namespace std;
int helper(int idx,int maxwet,vector<int>&wt,vector<int>&wetval){
    if(idx==0){
        return int(maxwet/wt[0]*wetval[0]);
    }
    int not_take=helper(idx-1,maxwet,wt,wetval);
    int take=-1e9;
    if(maxwet>=wt[idx]) take=wetval[idx]+helper(idx,maxwet-wt[idx],wt,wetval);
    return max(take,not_take);
}
int helper2(int idx,int maxwet,vector<int>&wt,vector<int>&wetval,vector<vector<int>>&dp){
    if(idx==0){
        return int(maxwet/wt[0]*wetval[0]);
    }
    if(dp[idx][maxwet]!=0) return dp[idx][maxwet];
    int not_take=helper(idx-1,maxwet,wt,wetval);
    int take=0;
    if(maxwet>=wt[idx]) take=wetval[idx]+helper(idx,maxwet-wt[idx],wt,wetval);
    return dp[idx][maxwet]=max(take,not_take);
}
int helper3(int idx,int maxwet,vector<int>&wt,vector<int>&wetval,vector<vector<int>>&dp){
        for(int i=0;i<=maxwet;i++){
            dp[0][i]=(int(i/wt[0])*wetval[0]);
        }
        for(int i=1;i<=idx;i++){
        for(int target=0;target<=maxwet;target++){
        int not_take=dp[i-1][target];
        int take=-1e9;
        if(target>=wt[i]) take=wetval[i]+dp[i][target-wt[i]];
        dp[i][target] = max(take,not_take);
        }
        } return dp[idx][maxwet];
}
int helperspaceoptimize(int idx,int maxwet,vector<int>&wt,vector<int>&wetval,vector<vector<int>>&dp){
    vector<int>prev(maxwet+1,0),curr(maxwet+1,0);
        for(int i=0;i<=maxwet;i++){
            prev[i]=int((i/wt[0])*wetval[0]);
        }
        for(int i=1;i<=idx;i++){
        for(int target=0;target<=maxwet;target++){
        int not_take=0+prev[target];
        int take=-1e9;
        if(target>=wt[i]) take=wetval[i]+curr[target-wt[i]];
        curr[target] = max(take,not_take);
        }prev=curr;
        } return prev[maxwet];
}
int helperspaceoptimizeultra(int idx,int maxwet,vector<int>&wt,vector<int>&wetval,vector<vector<int>>&dp){
    vector<int>prev(maxwet+1,0);//wow
        for(int i=0;i<=maxwet;i++){
            prev[i]=int((i/wt[0])*wetval[0]);
        }
        for(int i=1;i<=idx;i++){
        for(int target=0;target<=maxwet;target++){// think BOUT THIS much more
        int not_take=0+prev[target];
        int take=0;
        if(target>=wt[i]) take=wetval[i]+prev[target-wt[i]];
        prev[target] = max(take,not_take);
        }
        } return prev[maxwet];
}
int unboundedknapsack(int maxwet,vector<int>&wt,vector<int>&val){
     int idx=wt.size()-1;
     vector<vector<int>>dp(idx+1,vector<int>(maxwet+1,0));
     return helperspaceoptimizeultra(idx,maxwet,wt,val,dp);
}
int main() {
    vector<int>wt={2,4,6};
    vector<int>val={5,11,13};
    cout<<unboundedknapsack(11,wt,val)<<endl;
    return 0;
}