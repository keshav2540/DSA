#include <bits/stdc++.h>
using namespace std;
vector<int>eventualsafe(vector<int> adj[], int v)
{   vector<int>revadj[v];
    vector<int>indegree(v, 0);
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            revadj[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0)q.push(i);
    }
   vector<int>safenode;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        safenode.push_back(node);
        for(auto it:revadj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
    }}
    sort(safenode.begin(),safenode.end());
    return safenode;
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
  for(auto i:eventualsafe(adj,12))cout<<i<<" ";
  return 0;

}