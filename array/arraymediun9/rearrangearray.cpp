#include <bits/stdc++.h>
using namespace std;
void rearrange(vector<int>&nums){// by two pointer
    int i=0,j=0;
    int k=0;
    int n=nums.size();
    while(i<n && j<n){
         while(nums[i]>0) {i++;}
         while(nums[j]<=0) {j++;}
         swap( nums[k++],nums[j]);
         j++;
         swap( nums[k++],nums[i]);
         i++;
    }

}

int main() {
    vector<int>nums={3,1,-2,-5,2,-4,3};
    rearrange(nums);
    for(auto i:nums) cout<<i<<"   --> ";
    return 0;
}