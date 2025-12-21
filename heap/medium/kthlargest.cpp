#include <bits/stdc++.h>
using namespace std;
int kthlargest(vector<int>nums,int k){
    int j=0;
    priority_queue<int>pq;
    for(auto i:nums)pq.push(i);
    for(j=1;j<k;j++) pq.pop();
    return pq.top();
}

int main() {
    vector<int>nums={1,2,6,4,5,3};
   int k=3;
    cout<<kthlargest(nums,k);
    return 0;
}