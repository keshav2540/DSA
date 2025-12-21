#include <bits/stdc++.h>
using namespace std;
int way(vector<pair<int,int>>adj[],int v ,int src,int end){
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;; // dis ,node
    vector<int>dis(v,1e9);
    vector<int>way(v,0);
    way[src]=1;
    dis[src]=0;
    pq.push({0,0});
    while(!pq.empty()){
        int dist =pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int adjnode=it.first;
            int edn=it.second;
            if(dist+edn<dis[adjnode]){
              dis[adjnode]=dist+edn;
              pq.push({dis[adjnode],adjnode});
              way[adjnode]=way[node];
            }
            else if(dist+edn==dis[adjnode]){
                way[adjnode]=(way[node]+way[adjnode])%int(1e9+7);
            }
        }
    } return way[end]%int(1e9+7);
}
int main() {
 vector<pair<int,int>>adj[7];
 adj[0]={{4,5},{6,7},{1,2}};
 adj[1]={{0,2},{3,3},{2,3}};
 adj[2]={{1,3},{5,1}};
 adj[3]={{5,1},{6,3},{1,3}};
 adj[4]={{0,5},{6,2}};
 adj[5]={{2,1},{6,1},{3,1}};
 adj[6]={{0,7},{4,2},{3,3},{5,1}};
 cout<<way(adj,7,0,6);
    return 0;
}