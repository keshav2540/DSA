#include <bits/stdc++.h>
using namespace std;
bool helperSpaceOptimization(int n,int target,vector<int>&arr,vector<vector<bool>>&dp){
    vector<bool>prev(1+target,false),curr(1+target,false);
        prev[0]=curr[0]=true;
    prev[arr[0]]=true;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=target;k++){
            curr[k]=((prev[k])|(k>=arr[i]?prev[k-arr[i]]:false));
        }prev=curr;
    } return prev[target];
}
bool SumIspossible(vector<int>&arr,int target){
    int n=arr.size();
    vector<vector<bool>>dp(n,vector<bool>(target+1,0));
    return helperSpaceOptimization(n-1,target,arr,dp);

}
bool partionsumispossible(vector<int>&arr){
    int totalsum=0;
    for(auto it:arr){
        totalsum+=it;
    }
    if(totalsum&1) return false;
    return SumIspossible(arr,totalsum/2);
}
int main() {
 vector<int>arr={2,3,3,3,4,5};
 cout<<partionsumispossible(arr);
    return 0;
}