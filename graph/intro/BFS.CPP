#include <bits/stdc++.h>
using namespace std;
vector<int>bfs(vector<int>adj[],int v) //v=no 0f nodes
{vector<int>ans;
 vector<int>visit(v+1,false);
 queue<int>qu;
 qu.push(1);
 visit[1]=true;
 while(!qu.empty()){
    int node=qu.front();
    qu.pop();
    ans.push_back(node);
    for(auto i:adj[node]){
        if(!visit[i]){
            qu.push(i);
            visit[i]=true;
        }
    }
 } return ans;
}
int main() {
     vector<int>adj[9];
 adj[0]={};
 adj[1]={2,6};
 adj[2]={1,3,4};
 adj[3]={2};
 adj[4]={2,5};
 adj[5]={4,7};
 adj[6]={1,7,8};
 adj[7]={5,6};
 adj[8]={6};
 vector<int>ans=bfs(adj,8);
 for(auto i:ans)cout<<i<<" ";
    return 0;
}