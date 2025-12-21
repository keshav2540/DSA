// kahnsAlgo is use for(DAG)directed a Acycle graph
// but we detect a cycle
// this is apply for the dirested acycle graph sort according to can move
#include <bits/stdc++.h>
using namespace std;
bool iscycle(vector<int> adj[], int v)
{
    vector<int>indegree(v, 0);
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0)q.push(i);
    }
   int count=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
    }}
    return !(count==v);
}
int main()
{
    vector<int> adj[6] = {{}, {2}, {3}, {4,5}, {2}, {}};
   cout<<iscycle(adj, 6);
    return 0;
}