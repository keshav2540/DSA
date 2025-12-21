
// how return empty? ans;-> arr return {};
// this is apply for the dirested acycle graph sort according to can move
#include <bits/stdc++.h>
using namespace std;
bool iscoureseschedulde(vector<pair<int,int>>p,int v)
{ vector<int>adj[v];
    for(auto i:p){
    adj[i.first].push_back(i.second);}
    vector<int>indegree(v, 0);
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            indegree[it]++;
         } }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0)q.push(i);}
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
    return ans.size()==v;
}
int main()
{
    vector<pair<int,int>>vp={{0,1},{2,1},{3,2}};
    cout<<endl<<iscoureseschedulde(vp,4);
    return 0;
}