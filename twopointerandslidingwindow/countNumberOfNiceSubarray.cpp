#include <bits/stdc++.h>
using namespace std;
int ans(vector<int>nums,int odd){
    int count=0;
    if(odd<0) return 0;
    int l=0,r=0,sum=0;
    while(r<nums.size()){
        sum+=nums[r]%2;
        while(sum>odd){
            sum-=nums[l++]%2;
        }
        count+=r-l+1;
        r++;
    } return count; 
}


int sol(vector<int>nums,int odd){
    return ans(nums,odd)-ans(nums,odd-1);
}

int main() {
    vector<int>nums={1,2,1,1,1};// {1,0,1,0,0}
    int odd=3;
    cout<<sol(nums,odd);
    return 0;
}