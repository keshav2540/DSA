#include <bits/stdc++.h>
using namespace std;
vector<int>nextgretherII(vector<int>nums){
    vector<int>ans(nums.size(),-1);
    stack<int>s;
    for(int i=(2*nums.size()-1);i>=0;i--){
        while(!s.empty() && nums[i%nums.size()]>=s.top()){
            s.pop();
        }
        if(!s.empty()&& i<nums.size()) ans[i]=s.top();
        s.push(nums[i%nums.size()]);
    } return ans;
}

int main() {// circular array
    vector<int>nums={2,10,12,1,11};
    for(auto i:nextgretherII(nums)) cout<<i<<" ";
    return 0;
}