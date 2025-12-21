// this is same as unbounded ksnap problem;
// use wet array instead of these can use {1,2,3,4,5}array
#include <bits/stdc++.h>
using namespace std;
int helper(int idx, int maxwet, vector<int> &wetlength)
{
    if (idx == 0)
    {
        return int(maxwet * wetlength[0]);
    }
    int not_take = helper(idx - 1, maxwet, wetlength);
    int take = -1e9;
    if (maxwet >= idx + 1)
        take = wetlength[idx] + helper(idx, (maxwet - idx - 1), wetlength);
    return max(take, not_take);
}
int helper2(int idx, int maxwet, vector<int> &wetlength, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        return int(maxwet * wetlength[0]);
    }
    if (dp[idx][maxwet] != 0)
        return dp[idx][maxwet];
    int not_take = helper(idx - 1, maxwet, wetlength);
    int take = -1e9;
    if (maxwet >= idx + 1)
        take = wetlength[idx] + helper(idx, (maxwet - idx - 1), wetlength);
    return dp[idx][maxwet] = max(take, not_take);
}
int helper3(int idx,int maxwet,vector<int>&wetlength,vector<vector<int>>&dp){
        for(int i=0;i<=maxwet;i++){
            dp[0][i]=(int(i * wetlength[0]));
        }
        for(int i=1;i<=idx;i++){
        for(int target=0;target<=maxwet;target++){
        int not_take=dp[i-1][target];
        int take=-1e9;
        if(target>=i+1) take=wetlength[i]+dp[i][target-i-1];
        dp[i][target] = max(take,not_take);
        }
        } return dp[idx][maxwet];
}
int helperspaceoptimize(int idx,int maxwet,vector<int>&wetlength,vector<vector<int>>&dp){
    vector<int>prev(maxwet+1,0),curr(maxwet+1,0);
        for(int i=0;i<=maxwet;i++){
            prev[i]=int(i*wetlength[0]);
        }
        for(int i=1;i<=idx;i++){
        for(int target=0;target<=maxwet;target++){
        int not_take=0+prev[target];
        int take=-1e9;
        if(target>=(i+1)) take=wetlength[i]+curr[target-i-1];
        curr[target] = max(take,not_take);
        }prev=curr;
        } return prev[maxwet];
}
int helperspaceoptimizeultra(int idx,int maxwet,vector<int>&wetlength,vector<vector<int>>&dp){
    vector<int>prev(maxwet+1,0);//wow
        for(int i=0;i<=maxwet;i++){
            prev[i]=int(i*wetlength[0]);
        }
        for(int i=1;i<=idx;i++){
        for(int target=0;target<=maxwet;target++){
        int not_take=0+prev[target];
        int take=-1e9;
        if(target>=(i+1)) take=wetlength[i]+prev[target-(i+1)];
        prev[target] = max(take,not_take);
        }
        } return prev[maxwet];
}
int cuttingrod(int maxwet, vector<int> &length)
{
    int idx = length.size() - 1;
    vector<vector<int>> dp(idx + 1, vector<int>(maxwet + 1, 0));
    return helperspaceoptimizeultra(idx, maxwet, length, dp);
}
int main()
{
    vector<int> length = {2, 5, 7, 8, 10};
    cout << cuttingrod(5, length) << endl;
    return 0;
}