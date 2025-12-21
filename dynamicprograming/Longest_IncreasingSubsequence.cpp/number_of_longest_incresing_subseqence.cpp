// biotonic mean increasing + decresing
#include <bits/stdc++.h>
using namespace std;
int count(int n,vector<int>&arr){
    vector<int>dp(n,1);
    vector<int>cnt(n,1);
     int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]&& dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                cnt[i]=cnt[j];
                maxi=max(maxi,dp[i]);
        }
        else if(arr[i]>arr[j]&& dp[i]==dp[j]+1){
            cnt[i]+=cnt[j];
        }
    } 
} int ans=0;
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" "<<dp[i]<<" "<<cnt[i]<<endl;
   if(dp[i]==maxi)ans+=cnt[i];
   }
   return ans;
}
int main() {
    vector<int>arr={1,5,4,3,2,6,7,10,8,9};
    // vector<int>arr={1,3,5,4,7};
 cout<<count(arr.size(),arr);
    return 0;
}