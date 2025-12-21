#include <bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<int>adj[],int vis[],int pathvis[],int check[]){
    vis[node]=1;
    pathvis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            check[it]=0;
            if(dfs(it,adj,vis,pathvis,check)==true)return true;
        }
        else if(pathvis[it]){
            check[it]=0;
            return true;
        }}
    check[node]=1;
    pathvis[node]=0;
    return false;
}
bool isCycle(int v,vector<int>adj[]){
    int vis[v]={0};
    int pathvis[v]={0};
    int check[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
         dfs(i,adj,vis,pathvis,check);
        }}
    for(int i=0;i<v;i++){
        if(check[i])cout<<i<<" ";
    }    
    return 0;
}
int main() {
  vector<int>adj[12];
  // this is directed graph
  adj[0]={1};
  adj[1]={2};
  adj[2]={3};
  adj[3]={4,5};
  adj[4]={6};
  adj[5]={6};
  adj[6]={7};
  adj[7]={};
  adj[8]={1,9};
  adj[9]={10};
  adj[10]={8};
  adj[11]={9};
  cout<<isCycle(12,adj);
  return 0;

}