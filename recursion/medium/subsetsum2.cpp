#include <bits/stdc++.h>
using namespace std;
void helper(int ind,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
   ans.push_back(temp);
    for(int i=ind;i<nums.size();i++){
    if(i!=ind&& nums[i]==nums[i-1]) continue;
    temp.push_back(nums[i]);
    helper(i+1,nums,temp,ans);
    temp.pop_back();
   }
}vector<vector<int>>subsets2(vector<int>&nums,int n){
    vector<vector<int>>ans;
    vector<int>temp;
    sort(nums.begin(),nums.end());
    helper(0,nums,temp,ans);
    return ans;
}

int main() {
  vector<int>nums={1,2,3};
  vector<vector<int>>ans=subsets2(nums,3);
   for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    } cout<<endl;
   }
    return 0;
}