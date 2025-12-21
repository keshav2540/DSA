#include <bits/stdc++.h>
using namespace std;
vector<int>bellman_ford(int v,vector<vector<int>>&edges,int src){
    vector<int>dis(v,1e8);
    dis[src]=0;
 for(int i=0;i<v-1;i++){// relexsation n-1 time this is for only directed graph if graph is in dirested convert these to directed graph
    for(auto it:edges){// it do n-1 time any order may be edages and linear graph
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dis[u]!=1e8 && dis[u]+wt<dis[v]){// relexsation 
            dis[v]=dis[u]+wt;
        }
    }
 }
 //nth relexsation check nragative cycle;
 for(auto it:edges){
      int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dis[u]!=1e8&&dis[u]+wt<dis[v]){
            dis[v]=-1 ;// neagative cycle occure
        }
 }
 return dis;
}
int main() {
    vector<vector<int>>edges={{3,2,6},{5,3,1},{0,1,5},{1,5,-3},{1,2,-2},{3,4,-2},{2,4,3}};
   for(auto i:bellman_ford(6,edges,0)) cout<<i<<"  ";
    return 0;
}