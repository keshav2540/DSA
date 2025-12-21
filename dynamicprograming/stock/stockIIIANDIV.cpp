#include <bits/stdc++.h>
using namespace std; // buy and sell k times
int helper(int idx, bool buy, int cap, vector<int> &arr)
{
    if (idx == arr.size() || cap == 0)
        return 0;
    int profit = 0;
    if (buy)
    {
        profit = max(-arr[idx] + helper(idx + 1, 0, cap, arr), helper(idx + 1, 1, cap, arr));
    }
    else
    {
        profit = max(arr[idx] + helper(idx + 1, 1, cap - 1, arr), helper(idx + 1, 0, cap, arr));
    }
    return profit;
}
int helper2(int idx, bool buy, int cap, vector<int> &arr, vector<vector<vector<int>>> &dp)
{
    if (idx == arr.size() || cap == 0)
        return 0;
    if (dp[idx][buy][cap] != -1)
        return dp[idx][buy][cap];
    int profit = 0;
    if (buy)
    {
        profit = max(-arr[idx] + helper2(idx + 1, 0, cap, arr, dp), helper2(idx + 1, 1, cap, arr, dp));
    }
    else
    {
        profit = max(arr[idx] + helper2(idx + 1, 1, cap - 1, arr, dp), helper2(idx + 1, 0, cap, arr, dp));
    }
    return dp[idx][buy][cap] = profit;
}
int helper3(int idx, bool buy, int cap, vector<int> &arr, vector<vector<vector<int>>> &dp)
{
    // for (int i = 0; i <= buy; i++)
    // {
    //     for (int j = 0; j <= cap; j++)
    //     {
    //         dp[0][i][j] = 0;
    //     }
    // }          no need to write because dp all element alredy is 0
    // for (int i = 0; i <= buy; i++)
    // {
    //     for (int j = 0; j <=arr.size(); j++)
    //     {
    //         dp[j][i][0] = 0;
    //     }
    // }
    int i=buy,j=cap,k=idx;
    for (idx = arr.size() - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= i; buy++)
        {
            for (int cap = 1; cap <= j; cap++)
           { 
               if (buy)
               {
                     dp[idx][buy][cap]= max(-arr[idx] + dp[idx + 1][0][cap] ,dp[idx + 1][1][cap]);
               }
               else
               {
                     dp[idx][buy][cap] = max(arr[idx] + dp[idx + 1][1][cap-1], dp[idx + 1][0][cap]);
               }
                             }
                       }
          } return dp[k][i][j];
    }
int helper4(int idx, bool buy, int cap, vector<int> &arr, vector<vector<vector<int>>> &dp)
{   vector<vector<int>>after(2,vector<int>(cap+1,0)),curr(2,vector<int>(cap+1,0));
    int i=buy,j=cap,k=idx;
    for (idx = arr.size() - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy <= i; buy++)
        {
            for (int cap = 1; cap <= j; cap++)
           { 
               if (buy)
               {
                     curr[buy][cap]= max(-arr[idx] + after[0][cap] ,after[1][cap]);
               }
               else
               {
                     curr[buy][cap] = max(arr[idx] + after[1][cap-1], after[0][cap]);
               }
                }
                 }after=curr;
          }  return after[i][j];
    }
// we can change this to 0(N*2*cap)to O(N*cap*2)
// i use caps=2*cap;
// check cap%2==0; we can buy;
// cap= 2*cap return ans;
int helper5(int idx, int cap,const int caps, vector<int> &arr)//memorization use and tabulation can use
{
    if (idx == arr.size() || cap == caps)
        return 0;
    int profit = 0;
    if (cap%2==0)
    {
        profit = max(-arr[idx] + helper5(idx + 1, cap+1,caps, arr), helper5(idx + 1, cap, caps,arr));
    }
    else
    {
        profit = max(arr[idx] + helper5(idx + 1, cap+1,caps, arr), helper5(idx + 1, cap, caps,arr));
    }
    return profit;
}
int helper5tabulation(int idx, int cap,const int caps, vector<int> &arr)//memorization use and tabulation can use
{ vector<vector<int>>dp(arr.size()+1,vector<int>(caps+1,0));
    int i=idx,j=cap;
    for(idx=arr.size()-1;idx>=0;idx--){
        for(cap=caps-1;cap>=0;cap--) { 
    if (cap%2==0)
    {
         dp[idx][cap]  = max(-arr[idx] + dp[idx + 1][cap+1], dp[idx + 1][cap]);
    }
    else
    {
         dp[idx][cap] = max(arr[idx] + dp[idx + 1][cap+1],dp[idx + 1][cap]);
    } 
   }
    } return dp[0][0];
}
int maxprofit(vector<int> &arr, int k)
{
    vector<vector<vector<int>>> dp(arr.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
    // return helper4(0, 1, k, arr, dp);
    return helper5tabulation(0, 0,2*k, arr);
}
int main()
{
    vector<int> arr1 = {3, 3, 5, 0, 0, 3, 1, 4};  
    vector<int> arr2 = {3, 2,6,5,0,3};
    int k = 3;
    cout << maxprofit(arr1, k) << endl;
    cout << maxprofit(arr1, 2) << endl;
    cout << maxprofit(arr2, 2) << endl;
    return 0;
}