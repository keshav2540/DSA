#include <bits/stdc++.h>
using namespace std;
void helper(int ind,int sum,vector<int>&arr,int n,vector<int>&sumset){
    if(ind==n){
        sumset.push_back(sum);
        return;
    }
    helper(ind+1,sum+arr[ind],arr,n,sumset);//pick
    helper(ind+1,sum,arr,n,sumset);//not pick;
}vector<int>subsets(vector<int>arr,int n){
    vector<int>sumset;
    helper(0,0,arr,n,sumset);
    sort(sumset.begin(),sumset.end());
    return sumset;
}

int main() {
     vector<int>nums={1,2,3};
  int target=5;
  for(auto i:subsets(nums,3)) cout<<i<<" ";
    return 0;
}