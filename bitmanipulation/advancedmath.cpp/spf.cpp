#include <bits/stdc++.h>
using namespace std;
vector<int>getfactor(int n){
    vector<int>ans;
     for(int i=2;i*i<n;i++){
      if(n%i==0){
       
        while(n%i==0) {
        ans.push_back(i);
        n=n/i;}
      }
    } 
    if(n!=1) ans.push_back(n);
    return ans;
}
 vector<vector<int>>primefactor(vector<int>nums){
    vector<vector<int>>matrix;
    for(int i=0;i<nums.size();i++){
        matrix.push_back(getfactor(nums[i]));
    } return matrix;
}
vector<int>spf(int n){
    vector<int>nums;
    for(int i=0;i<n;i++){
        nums.push_back(i);
    }
    for(int i=2;i*i<=n;i++){
        if(nums[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(nums[j]==j) nums[j]=i;
            }
        }
    } return nums;
}
 vector<vector<int>>spfmethod(vector<int>nums){
    vector<int>num=spf(1e+6);
    vector<vector<int>>result;
    int k=nums.size();
    for(int i=0;i<k;i++){
      int  n=nums[i];
        vector<int>ans;
        while(n!=1){
            ans.push_back(num[n]);
            n=n/num[n];
        } 
        result.push_back(ans);
    } return result;
}

int main() {
    vector<int>nums={12,16,60};
    vector<vector<int>>mat=spfmethod(nums);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            cout<<mat[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}