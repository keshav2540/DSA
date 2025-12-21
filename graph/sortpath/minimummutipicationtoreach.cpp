#include <bits/stdc++.h>
using namespace std;
int minimumMultipication(vector<int>&arr,int start,int end){
    queue<pair<int,int>>q;
    q.push({start,0});
    vector<int>dis(1e5,1e9);
    dis[start]=0;
    int mod=1e5;
    while(!q.empty()){
        int node=q.front().first;
        int step=q.front().second;
        q.pop();
        for(auto &i:arr){
            int num=(i*node)%mod;
            if(step+1<dis[num]){
                dis[num]=step+1;
                if(num==end)return step+1;
                q.push({num,step+1});
            }
        }
    }return -1;
}
int main() {
    vector<int>arr={3,4,65};
    cout<<minimumMultipication(arr,7,66175);
    return 0;
}