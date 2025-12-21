#include <bits/stdc++.h>
using namespace std;
vector<int>nextgrether(vector<int>nums){
    vector<int>ans(nums.size(),-1);
    stack<int>s;
    for(int i=nums.size()-1;i>=0;i--){
        while(!s.empty() && nums[i]>=s.top()){
            s.pop();
        }
        if(!s.empty()) ans[i]=s.top();
        s.push(nums[i]);
    } return ans;
}

int main() {
    vector<int>nums={4,12,5,3,1,2,5,3,1,2,4,6};
    for(auto i:nextgrether(nums)) cout<<i<<" ";
    return 0;
}