//node who remove graph is divided many component//multiple parts
//tin is same
// low  store min of all adjcent node apart from parent and visioted node;
#include <bits/stdc++.h>
using namespace std;
int timer=1;
void dfs(int node,int parent,vector<int>&vis,int tin[],int low[],vector<int>&mark,vector<int>adj[]){
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    int child=0;
    for(auto it :adj[node]){
        if(it==parent) continue;
        if(vis[it]==0){
            dfs(it,node,vis,tin,low,mark,adj);
            low[node]=min(low[node],low[it]);
            if(low[it]>=tin[node] && parent!=-1){//check articulationpoint
              mark[node]=1;
            }
            child++;
        }
        else{
            low[node]=min(low[node],tin[it]);
        }
    }
    if(child>1&& parent==-1){
        mark[node]+=1;
    }
}
vector<int>articulationpoint(int n,vector<int>adj[]){
    vector<int>vis(n,0);
    int tin[n];
    int low[n];
    vector<int>mark(n,0);
    for(int i=0;i<n;i++){
        if(!vis[0]){
            dfs(i,-1,vis,tin,low,mark,adj);
        }
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(mark[i]==1){
            ans.push_back(i);
        }
    }
    if(ans.size()==0) return {-1};
    else return ans;
}
int main() {
    vector<int>adj[8]={{1,2,3},{0},{0,3,4,5},{0,2},{2,6},{2,6},{4,5}};
    for(auto it:articulationpoint(8,adj)){
    cout<<it<<endl;
        }
    return 0;
}