#include <bits/stdc++.h>
using namespace std;
void permutations2(int idx,vector<int>&nums,vector<vector<int>>&ans){
    if(idx==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
         permutations2(idx+1,nums,ans);
         swap(nums[i],nums[idx]);  
    }
}
int main() {
    vector<int>arr={1,2,3};
    vector<vector<int>>ans;
    permutations2(0,arr,ans);
    for(auto &s:ans){
    for(auto i:s){
        cout<<i<<" ";
    } cout<<endl;
   }
    return 0;
}