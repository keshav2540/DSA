#include <bits/stdc++.h>
using namespace std;
void toposort(int node,vector<pair<int,int>>adj[],int vis[],stack<int>&st){
    vis[node]=1;
    for(auto i:adj[node]){
        int v=i.first;
        if(!vis[v]){
            toposort(v,adj,vis,st);
        }
    }
    st.push(node);
}
vector<int>shortestpath(int n,vector<vector<int>>edges ){
    vector<pair<int,int>>adj[n];
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int wet=edge[2];
        adj[u].push_back({v,wet});
    }
    int vis[n]={0};
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            toposort(i,adj,vis,st);
        }
    }
    vector<int>dist(n);
    for(int i=0;i<n;i++) dist[i]=1e9;
    dist[0]=0; // this this palce we decided where we start 
    while(!st.empty()){
        int node=st.top();
        st.pop();
        for(auto it:adj[node]){
            int v=it.first;
            int wt=it.second;
            if(dist[node]+wt<dist[v]){
                dist[v]=dist[node]+wt;
            }
        }
    }
    return dist;
}
int main() {
    vector<vector<int>>edges={{0,1,2},{1,3,1},{2,3,3},{4,0,3},{4,2,1},{5,4,1},{6,4,2},{6,5,3}};
    for(int i:shortestpath(7,edges)){
        if(i==1e9)cout<<" not reach  ";
        else cout<<i<<" ";
    }
    return 0;
}