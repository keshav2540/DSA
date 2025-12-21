/* this algo for strongly connected component of graph is find*/
#include <bits/stdc++.h>
using namespace std;
void dfs1(int node,vector<int>&vis,vector<int>adj[],stack<int>&st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs1(it,vis,adj,st);
        }
    }st.push(node);
}
void dfs2(int node,vector<int>&vis,vector<int>adj[]){
    vis[node]=1;
    cout<<node<<" ";
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs2(it,vis,adj);
        }
    }
}
int kosaraju(int v,vector<int>adj[]){
    vector<int>vis(v,0);
    stack<int>st;
    for(int i=0;i<v;i++){
 if(!vis[i]){
    dfs1(i,vis,adj,st);
 }
    }

vector<int>adjt[v];
for(int i=0;i<v;i++){//reverse graph
    vis[i]=0;
    for(auto it:adj[i]){
        adjt[it].push_back(i);
    }
}
int scc=0;
while(!st.empty()){
    int node=st.top();
    st.pop();
    if(!vis[node]){
        scc++;
        dfs2(node,vis,adjt);
        cout<<endl;
    }
} return scc;
}
int main() {
 vector<int>adj[8];
 adj[0]={1};
 adj[1]={2};
 adj[2]={0,3};
 adj[3]={4};
 adj[4]={5,7};
 adj[5]={6};
 adj[6]={4};
 cout<<kosaraju(8,adj);
    return 0;
}