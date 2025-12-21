#include <bits/stdc++.h>
using namespace std;
bool detectBFS(int src,vector<int>adj[],int vis[]){
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adjnode:adj[node]){
            if(!vis[adjnode]){
                vis[adjnode]=1;
                q.push({adjnode,node});
            }
            else if(parent!=adjnode){
                return true;
            }
        }
    } return false;
}
bool detectDFS(int src,int parent,vector<int>adj[],int vis[]){
   vis[src]=1;
   for(auto it:adj[src]){
    if(!vis[it]){
        if(detectDFS(it,src,adj,vis)==true) return true;
    }
    else if(it!=parent){
        return true;
    }
   } return false;
}
bool iscycle(int v,vector<int>adj[]){
    int vis[v]={0};
    for(int i=1;i<v;i++){
        if(!vis[i]){
            if(detectDFS(i,-1,adj,vis)==true) return true;
        }
    } return false;
}
int main() {
    vector<int>adj[8];
    adj[1]={2,3};
    adj[2]={1,5};
    adj[3]={1,4,6};
    adj[4]={3};
    adj[5]={2,7};
    adj[6]={7,3};
    adj[7]={5,6};
   cout<<iscycle(8,adj);
  return 0;
}