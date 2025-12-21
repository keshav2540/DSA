#include <bits/stdc++.h>
using namespace std;
int single(vector<int>nums){
    int X0r=0;
    for(int i=0;i<nums.size();i++)X0r=X0r^nums[i];
    return X0r;
}
int bf(vector<int>nums){
    map<int,int>m;
     for(int i=0;i<nums.size();i++) m[nums[i]]++;
     for(auto it:m)if(it.second==1) return it.first;
     return 0;
}

int main() {
    vector<int>nums={4,1,2,1,2};
    cout<<bf(nums);
    return 0;
}