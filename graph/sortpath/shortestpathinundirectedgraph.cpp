#include <bits/stdc++.h>
using namespace std;
vector<int>sortestpath(vector<vector<int>>edge,int v,int st){// dis between node is one unit
vector<int>adj[v];
for(auto it:edge){
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
}
int dis[v];
for(int i=0;i<v;i++)dis[i]=1e9;
dis[st]=0;
queue<int>q;
q.push(st);
while(!q.empty()){
    int node=q.front();
    q.pop();
    for(auto i:adj[node]){
        if(dis[node]+1<dis[i])
      {  dis[i]=dis[node]+1;
        q.push(i);}
    }
}
vector<int>ans(v,-1);
for(int i=0;i<v;i++){
    if(dis[i]!=1e9){ ans[i]=dis[i];}
    cout<<ans[i]<<" ";
} 
return ans;
}

int main() {
vector<vector<int>>edge={{0,1}, {0,3}, {3,4}, {4 ,5}
,{5, 6}, {1,2}, {2,6}, {6,7}, {7,8}, {6,8}};
sortestpath(edge,9,0);
    return 0;
}