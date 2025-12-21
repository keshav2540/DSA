// which edge when we remove which eddge graph is convert two componenet //
// two arry called this tarjan algo 
//tin =dfs time of insertion 
// low=min od lowest time insertion of all adacent apart from parent
#include <bits/stdc++.h>
using namespace std;
int timer=1;
void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],int tin[],int low[],vector<vector<int>>&bridge){
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it :adj[node]){
        if(it==parent) continue;
        if(vis[it]==0){
            dfs(it,node,vis,adj,tin ,low,bridge);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node]){//check brige
              bridge.push_back({it,node});
            }
        }
        else{
            low[node]=min(low[node],low[it]);
        }
    }
}
vector<vector<int>>criticialpoint(int n,vector<vector<int>>&connection){
    vector<int>adj[n];// tc=o(v+2e)+O(3N);
    for(auto it:connection){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>vis(n,0);
    int tin[n];
    int low[n];
    vector<vector<int>>bridge;
    dfs(1,-1,vis,adj,tin,low,bridge);
    return bridge;// use loop for many component graph
}
int main() {
    vector<vector<int>>connection={{1,2},{2,3},{3,4},{1,4},{4,5},{5,6},{6,7},{6,9},{7,8},{8,9},{8,10},{10,11},{11,12},{12,10}};
    for(auto it:criticialpoint(13,connection)){
    cout<<it[0]<<"  "<<it[1]<<endl;
        }
    return 0;
}