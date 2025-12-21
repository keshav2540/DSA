/* spappaing tree which tree have n node and n-1 edges we go one node to another node mean all nodes is aceessable*/
#include <bits/stdc++.h>
using namespace std;
int spaningtree(vector<vector<int>>adj[],int v){
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>vis(v,0);
  pq.push({0,0}); // if we want minimumspaning tree take one more parameyr parent
      int sum=0;
       while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.first;
        int wt=it.second;
        if(!vis[node])continue;
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node]){
            int adjnode=it[0];
            int adjnodewt=it[1];
            if(!vis[adjnode]){
                pq.push({adjnodewt,adjnode});
            }
        }
       }return sum;
    }
int main() {
    vector<vector<int>>adj[5];
    adj[0]={{1,2},{2,1}};
    adj[1]={{1,2},{2,1}};
    adj[2]={{1,1},{0,1},{4,2},{3,2}};
    adj[3]={{2,2},{4,1}};
    adj[4]={{2,2},{3,1}};
    cout<<spaningtree(adj,5);
    return 0;
}