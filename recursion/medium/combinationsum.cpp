#include <bits/stdc++.h>
using namespace std;
void helper(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
    if(ind==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return;
    }
    if( arr[ind]<=target){
        ds.push_back(arr[ind]);
        helper(ind,target-arr[ind],arr,ans,ds);
        ds.pop_back();
    }
        helper(ind+1,target,arr,ans,ds);
}
  

vector<vector<int>>combination(vector<int>nums,int target){
    vector<vector<int>>ans;
    vector<int>temp;
   sort(nums.begin(), nums.end());
    helper(0,target,nums,ans,temp);
 return ans;}

int main() {
  vector<int>nums={1,2,3};
  int target=5;
  vector<vector<int>>ans=combination(nums,target);
   for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    } cout<<endl;
   }
    return 0;
}