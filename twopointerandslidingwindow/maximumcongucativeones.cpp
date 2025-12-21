#include <bits/stdc++.h>
using namespace std; //can flip  k zero
 int consectiveonesbf(vector<int>nums,int k){
  ; int maxcount=0;
    for(int i=0;i<nums.size();i++)
{    int zero=0;int  count=0;
     for(int j=i;j<nums.size();j++){
    if(nums[j]==0)zero++;
       if(zero>k) break; 
        count++;
 
}maxcount=max(maxcount,count);
} return maxcount;
}
int consectiveonesbetter(vector<int>nums,int k){
    int l=0,r=0,maxlength=0,zero=0;
    while(r<nums.size()){
        if(nums[r]==0)zero++;
        while(zero>k){
            if(nums[l]==0) zero--;
            l++;
        }
        if(zero<=k){
            maxlength=max(maxlength,r-l+1);
        }r++;
    }return maxlength;
}
 
int consectiveonesoptimal(vector<int>nums,int k){
    int l=0,r=0,maxlength=0,zero=0;
    while(r<nums.size()){
        if(nums[r]==0)zero++;
        if(zero>k){
            if(nums[l]==0) zero--;
            l++;
        }
        if(zero<=k){
            maxlength=max(maxlength,r-l+1);
        }r++;
    }return maxlength;
}
 


int main() {
    vector<int>nums={1,1,1,0,0,0,1,1,1,1,1,0};
    int k=2;
     cout<<consectiveonesoptimal(nums,k);
    return 0;
}