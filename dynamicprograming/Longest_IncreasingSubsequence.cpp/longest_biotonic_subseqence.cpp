// biotonic mean increasing + decresing
#include <bits/stdc++.h>
using namespace std;
int loongestBiotonicSubseqence(int n,vector<int>&arr){
    vector<int>dp1(n,1);
    vector<int>dp2(n,1);
     int lastindex=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]&& dp1[i]<dp1[j]+1){
                dp1[i]=dp1[j]+1;
        }
    } }
   for(int i=n-1;i>=0;i--){
    for(int j=n-1;j>i;j--){
         if(arr[i]>arr[j]&& dp2[i]<dp2[j]+1){
                dp2[i]=dp2[j]+1;
        }
    }
   }
   int maxi=0;
   for(int i=0;i<n;i++){
    cout<<dp1[i]<<" "<<dp2[i]<<endl;
    maxi=max(maxi,dp1[i]+dp2[i]-1);
   }
   return maxi;
}
int main() {
    vector<int>arr={1,11,2,10,4,5,2,1};
 cout<<loongestBiotonicSubseqence(arr.size(),arr);
    return 0;
}