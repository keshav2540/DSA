#include <bits/stdc++.h>
using namespace std;
void helper(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
    if(target==0){
          ans.push_back(ds);
        return;
    }
    for(int i=0;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>target)break;
        ds.push_back(arr[i]);
        helper(i+1,target-arr[i],arr,ans,ds);
        ds.pop_back();
    }
}
  
vector<vector<int>>combination2(vector<int>nums,int target){
    vector<vector<int>>ans;
    vector<int>temp;
   sort(nums.begin(), nums.end());
    helper(0,target,nums,ans,temp);
 return ans;}

int main() {
  vector<int>nums={1,2,3};
  int target=5;
  vector<vector<int>>ans=combination2(nums,target);
   for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    } cout<<endl;
   }
    return 0;
}