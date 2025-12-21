#include <bits/stdc++.h>
using namespace std;
vector<int>replacebf(vector<int>nums){
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
    set<int>s;
    for( int j=0;j<nums.size();j++){
        if(nums[i]>nums[j]){s.insert(nums[j]);}
    }
    ans.push_back(s.size()+1);
    }
 return ans;
}
vector<int>replaceby(vector<int>nums){int l=1;
    map<int,int>m;
    vector<int>copy=nums;
    sort(copy.begin(),copy.end());
    for(int i:copy)m[i]=l++;
    for(int i=0;i<nums.size();i++){
        nums[i]=m[nums[i]];
    } return nums;
}
int main() {
    vector<int>nums={20 ,15, 26, 2, 98, 6};
    for(int i :replaceby(nums)) cout<<i<<" ";
    return 0;
}