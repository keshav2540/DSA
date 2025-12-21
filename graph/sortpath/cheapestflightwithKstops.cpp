#include <bits/stdc++.h>
using namespace std;
int cheapestflight(int v,vector<pair<int,int>>flight[],int src,int dst,int k){
       queue<pair<int,pair<int,int>>>q;
       q.push({0,{src,0}});// steo,node,dis
       vector<int>dis(v,1e9);
       dis[src]=0;
       while(!q.empty()){
        auto it=q.front();
        q.pop();
        int stop=it.first;
        int node=it.second.first;
        int dist=it.second.second;
        if(stop>k)continue;
        for(auto i:flight[node]){
            int adjnode=i.first;
            int edn=i.second;
            if(dist+edn<dis[adjnode]&& stop<=k){
                dis[adjnode]=dist+edn;
                q.push({stop+1,{adjnode,dis[adjnode]}});
            }
        }
       }return dis[dst]==1e9?-1:dis[dst];
}
int main() {
    vector<pair<int,int>>adj[5];
    adj[0]={{1,5},{3,2}};
    adj[1]={{2,5},{4,1}};
    adj[3]={{1,2}};
    adj[4]={{2,1}};
 cout<< cheapestflight(5,adj,0,2,3);
    return 0;
}