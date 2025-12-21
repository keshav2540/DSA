#include <bits/stdc++.h>
using namespace std;
vector<int>mindistance(int v,vector<vector<int>>adj[],int src){
    set<pair<int,int>>st;
    vector<int>dist(v,1e9);
   dist[src]=0;
   st.insert({0,src});
   while(!st.empty()){
    auto it=*(st.begin());
    int node=it.second;
    int nodedist=it.first;
    st.erase(it);
    for(auto i:adj[node]){
        int adjnode=i[0];
        int adjdis=i[1];
           if(adjdis+nodedist<dist[adjnode]){
            if(dist[adjnode]!=1e9)st.erase({dist[adjnode],adjnode});
            dist[adjnode]=adjdis+nodedist;
            st.insert({dist[adjnode],adjnode});
           }  }
   }
 return dist;
}
int main() {
vector<vector<int>>adj[6];
adj[0]={{1,4},{2,4}};
adj[1]={{0,4},{2,2}};
adj[2]={{0,4},{1,2},{3,3},{4,1},{5,6}};
adj[3]={{2,3},{5,2}};
adj[4]={{2,1},{5,3}};
adj[5]={{2,6},{3,2},{4,3}};

for(auto i:mindistance(6,adj,0)){cout<<i<<" ";}

    return 0;
}