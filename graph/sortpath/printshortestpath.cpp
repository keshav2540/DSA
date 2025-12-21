#include <bits/stdc++.h>
using namespace std;
vector<int>path(int v,vector<vector<int>>adj[],int src,int dst){//dst disteny
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(v,1e9);
    vector<int>parent(v);
    for(int i=0;i<v;i++)parent[i]=i;
   dist[src]=0;
   pq.push({0,src});
   while(!pq.empty()){
    int node=pq.top().second;
    int nodedist=pq.top().first;
    pq.pop();
    for(auto i:adj[node]){
        int adjnode=i[0];
        int adjdis=i[1];
           if(adjdis+nodedist<dist[adjnode]){
            parent[adjnode]=node;
            dist[adjnode]=adjdis+nodedist;
            pq.push({dist[adjnode],adjnode});
           }  }
   }
  vector<int>ans;
  int node=5;
  while(node!=parent[node]){
    ans.push_back(node);
    node=parent[node];
  }
  ans.push_back(src);
 reverse(ans.begin(),ans.end());
 return ans;
}
int main() {
vector<vector<int>>adj[6];
adj[0]={};
adj[1]={{2,2},{4,1}};
adj[2]={{1,2},{5,5},{3,4}};
adj[3]={{4,3},{2,4},{5,1}};
adj[4]={{1,1},{3,3}};
adj[5]={{2,5},{3,1}};

for(auto i:path(6,adj,1,5)){cout<<i<<" ";}
    return 0;
}