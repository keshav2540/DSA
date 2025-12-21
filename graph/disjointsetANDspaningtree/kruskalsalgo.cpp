#include <bits/stdc++.h>
using namespace std;
class disjointset{
    vector<int>rank,parent,size;
    public:
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findpar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int pv=findpar(v);
        int pu=findpar(u);
        if(pv==pu)return ;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv]){
           parent[pv]=pu;
        }
        else {
              parent[pv]=pu;
              rank[pu]++;
        }
    }
    void unionbysize(int u,int v){
          int pv=findpar(v);
        int pu=findpar(u);
        if(pv==pu)return ;
         if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else {
              parent[pv]=pu;
              size[pu]+=size[pv];
        }

    }
};
int spanningtreemst(vector<vector<int>>adj[],int v)//it return minimum mst sum
{
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            int adjnode=it[0];
            int wt=it[1];
            int node=i;
            edges.push_back({wt,{node,adjnode}});
        }
    }sort(edges.begin(),edges.end());
    int mstwt=0;
    disjointset ds(v);
    for(auto it:edges){
        int wt=it.first;
        int u=it.second.first;
        int V=it.second.second;
        if(ds.findpar(u)!=ds.findpar(V)){
           mstwt+=wt;
           ds.unionbysize(u,V);
        }
    }return mstwt;
}
int main(){
    vector<vector<int>>adj[7];
    adj[1]={{4,1},{2,2},{5,4}};
    adj[2]={{3,3},{4,3},{6,7}};
    adj[3]={{6,8},{4,5}};
    adj[4]={{5,9}};
    cout<<spanningtreemst(adj,7);
}