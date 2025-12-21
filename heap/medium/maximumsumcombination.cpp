#include <bits/stdc++.h>
using namespace std;
vector<int>maximumsum(vector<int>nums1,vector<int>nums2,int k){
    vector<int>ans(k);
    priority_queue<int>heap1;
    priority_queue<int>heap2;
   for(int i=0;i<nums1.size();i++){
    heap1.push(nums1[i]);
    heap2.push(nums2[i]);
   }
   ans[0]=(heap1.top()+heap2.top());
   for(int i=1;i<=k-1;i++){
    int top1=heap1.top();heap1.pop();
    int top2=heap2.top();heap2.pop();
    if(!heap1.empty()&&!heap2.empty()&&top1+heap2.top()>top2+heap1.top()){
        heap1.push(top1);
        ans[i]=(heap1.top()+heap2.top());
    }
    else {
        if(!heap1.empty()&&!heap2.empty()){
             heap2.push(top2);
        ans[i]=(heap1.top()+heap2.top());
        }
        else return ans;
    }
   }return ans;
}
int main() {
    vector<int>nums1={5,4,3};
    vector<int>nums2={6,3,2};
    for(auto i:maximumsum(nums1,nums2,4))cout<<i<<endl;;

    return 0;
}