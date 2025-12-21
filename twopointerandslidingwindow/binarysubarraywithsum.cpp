#include <bits/stdc++.h>
using namespace std;
int ans(vector<int>nums,int goal){
    int count=0;
    if(goal<0) return 0;
    int l=0,r=0,sum=0;
    while(r<nums.size()){
        sum+=nums[r];
        while(sum>goal){
            sum-=nums[l++];
        }
        count+=r-l+1;
        r++;
    } return count; 
}


int sol(vector<int>nums,int goal){
    return ans(nums,goal)-ans(nums,goal-1);
}

int main() {
    vector<int>nums={1,0,1,0,1};
    int goal=2;
    cout<<sol(nums,goal);
    return 0;
}