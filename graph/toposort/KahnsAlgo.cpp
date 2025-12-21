// this is apply for the dirested acycle graph sort according to can move
#include <bits/stdc++.h>
using namespace std;
vector<int> toposortbyBFS(vector<int> adj[], int v)
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
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        cout<<node<<" ";
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
    }}
    return ans;
}
int main()
{
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    toposortbyBFS(adj, 6);
    return 0;
}