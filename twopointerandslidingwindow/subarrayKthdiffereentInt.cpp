#include <bits/stdc++.h>
using namespace std;
int ans(vector<int>nums,int k){
    int count=0;   map<int,int>m;
    int l=0,r=0,sum=0;
    while(r<nums.size()){
        m[nums[r]]++;
        while(m.size()>k){
            m[nums[l]]--;
            if(m[nums[l]]==0) m.erase(nums[l]);
            l++;
        }
        count+=r-l+1;
        r++;
    } return count; 
}


int sol(vector<int>nums,int k){
    return ans(nums,k)-ans(nums,k-1);
}

int main() {
    vector<int>nums={1,2,1,3,4};// {1,0,1,0,0}
    int k=3;
    cout<<sol(nums,k);
    return 0;
}