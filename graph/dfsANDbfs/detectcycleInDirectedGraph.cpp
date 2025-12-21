#include <bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<int>adj[],int vis[],int pathvis[]){
    vis[node]=1;
    pathvis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,pathvis)==true)return true;
        }
        else if(pathvis[it]){
            return true;
        }}
    pathvis[node]=0;
    return false;
}
bool isCycle(int v,vector<int>adj[]){
    int vis[v]={0};
    int pathvis[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
         if(dfs(i,adj,vis,pathvis)==true)return true;
        }}
    return false;
}
int main() {
  vector<int>adj[11];
  adj[1]={2};
  adj[2]={3};
  adj[3]={4,7};
  adj[4]={5};
  adj[5]={6};
  adj[6]={};
  adj[7]={5};
  adj[8]={9};
  adj[9]={10};
  adj[10]={8};
  cout<<isCycle(11,adj);
  return 0;

}