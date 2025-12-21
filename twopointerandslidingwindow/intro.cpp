#include <bits/stdc++.h>
using namespace std;
int maxsum(vector<int>nums,int k)// return maxsum sizek window
{ int l=0,r=l+3; int sum=0,maxsum=sum;
    for(int i=l;i<=r;i++) {
        sum=sum+nums[i]; 
        maxsum=max(maxsum,sum);}
    while(r<nums.size()-1){
        sum=sum-nums[l++];
        sum=sum+nums[++r];
        maxsum=max(maxsum,sum);
    } return maxsum;
}
 int longestsubarraybf(vector<int>nums,int k)// maximumsum=k
{int maxlength=0; 
    for(int i=0;i<nums.size();i++)
{        int sum=0;int length=0;
    for(int j=i;j<nums.size();j++){sum=sum+nums[j];
        if(sum>k)break;
        length=j-i+1;
maxlength=max(maxlength,length);}
} return maxlength;
}
int longestsubarraybetter(vector<int>nums,int k){
    int l=0,r=0,sum=0,maxlength=0;
   while(r<nums.size()){
        sum+=nums[r];
    while(sum>k){
        sum=sum-nums[l++];
    }
    maxlength=max(maxlength,r-l+1);
    r++;
    } return maxlength;
   }
int longestsubarrayoptimal(vector<int>nums,int k){//ek bar windoe size bad gayi  na to window size ko kam nhi hone dena ye
    
    int l=0,r=0,sum=0,maxlength=0;
   while(r<nums.size()){
        sum+=nums[r];
    if(sum>k){
        sum=sum-nums[l++];
    }
    maxlength=max(maxlength,r-l+1);
    r++;
    } return maxlength;
   }

int main() {
    vector<int>nums={-1,2,3,3,4,5,-1};
    int k=4;
    cout<<longestsubarrayoptimal(nums,15);
    return 0;
}