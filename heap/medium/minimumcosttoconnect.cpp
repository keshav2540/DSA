#include <bits/stdc++.h>
using namespace std;
int minmumcost(vector<int>nums){
    int ans=0;
  priority_queue<int,vector<int>,greater<int>>heap;
     for(auto i:nums) heap.push(i);
     int k=heap.top();heap.pop();
     for(int i=1;i<nums.size();i++){
        k=k+heap.top();heap.pop();
        ans+=k;
     }return ans;
}
int main() {
    vector<int>nums={1, 8, 3, 5};
    cout<<minmumcost(nums);
    return 0;
}