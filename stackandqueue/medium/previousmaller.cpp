#include <bits/stdc++.h>
using namespace std;
vector<int>previoussmaller(vector<int>nums){
    vector<int>ans(nums.size(),-1);
    stack<int>s;
    for(int i=0;i<nums.size();i++){
        while(!s.empty() && nums[i]<s.top()){
            s.pop();
        }
        if(!s.empty()) ans[i]=s.top();
        s.push(nums[i]);
    } return ans;
}

int main() {
    vector<int>nums={5,7,9,6,7,4,5,1,3,7};
    for(auto i:previoussmaller(nums)) cout<<i<<" ";
    return 0;
}