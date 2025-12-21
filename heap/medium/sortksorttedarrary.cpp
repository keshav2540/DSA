#include <bits/stdc++.h>
using namespace std;
void sortkbf(vector<int>&arr,int k){int i;
    priority_queue<int,vector<int>,greater<int>>pq;
    for( i=0;i<4;i++){
        pq.push(arr[i]);
    }
    while(!pq.empty()&&i<arr.size()){
        arr[i-4]=pq.top();
        pq.pop();
        pq.push(arr[i]);
        i++;
    }
    for(;(i-4)<arr.size();i++){
        arr[i-4]=pq.top();
        pq.pop();
    }
}

int main() {vector<int>arr={1,4,5,2,3,6,7,8,9,10};
int k=2;
sortkbf(arr,k);
for(int i:arr)cout<<i<<" ";
    return 0;
}