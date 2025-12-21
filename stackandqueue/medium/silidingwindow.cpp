#include <bits/stdc++.h>
using namespace std;
vector<int>silidingwindowmaximum(vector<int>nums,int k){
    deque<int>dq;
    vector<int>list;
    for(int i=0;i<nums.size();i++){
    if(!dq.empty()&& dq.front()<=i-k)dq.pop_front();
    while(!dq.empty()&& nums[dq.back()]<=nums[i]){dq.pop_back();} 
    dq.push_back(i); 
    if(i>=k-1)list.push_back(nums[dq.front()]);  
} return list;
}

int main() {
vector<int>nums={1,3,-1,-3,5,3,2,1,6};
for(auto i:silidingwindowmaximum(nums,3)) cout<<i<<" ";
    return 0;}