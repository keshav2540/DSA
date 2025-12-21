#include <bits/stdc++.h>
using namespace std;
vector<int> toposortbyBFS(vector<int> adj[], int v)
{
    vector<int>indegree(v, 0);
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            // cout<<it<<" ";
            indegree[it]++;
        } //cout<<":   "<<i<<endl;
    }cout<<endl<<endl;
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
string findorder(string dict[],int N,int v){
  vector<int>adj[v];
  for(int i=0;i<N-1;i++){
    string s1=dict[i];
    string s2=dict[i+1];
    int len=min(s1.size(),s2.size());
    for(int k=0;k<len;k++){
        if(s1[k]!=s2[k]){
            adj[s1[k]-'a'].push_back(s2[k]-'a');
            break;
        }
    }}
    vector<int>topo=toposortbyBFS(adj,v);
    string ans=" ";
    for(auto i:topo){
        ans+=char(i+'a');
    } return ans;
  
}
int main() {
    string dict[]={"baa","abcd","abca","cab","cad"};
    cout<<findorder(dict,5,4);
    return 0;
}