#include <bits/stdc++.h>
using namespace std;
int f2(int n,vector<int>&arr){
    sort(arr.begin(),arr.end());// we can subset divisiblity depend on sort data
    int lcs=0;
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0){
                dp[i]=max(dp[i],dp[j]+1);
            }
            lcs=max(lcs,dp[i]);
        }
    } return lcs;
}
int f_usingalgo_PRINT(int n,vector<int>&arr){
     sort(arr.begin(),arr.end());
    int lcs=0;
    vector<int>dp(n,1);
    vector<int>hash(n,1);
     int lastindex=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0&& dp[i]<dp[j]+1){
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
 return f_usingalgo_PRINT(n,arr);
}
int main() {
 vector<int>arr={1,16,7,8,4};
 cout<<f_usingalgo_PRINT(5,arr);
    return 0;
}