#include <bits/stdc++.h>
using namespace std;
class solution
{
    void dfs(int node, vector<int> adj[], int vis[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis);
            }
        }
    }

public:
    int countpreivences(vector<int >adj[],int v){
         int vis[v]={0};
         int count=0;
         for(int i=1;i<v;i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
         }return count ;
    } 
};
 int main()
{
    vector<int> adj[9];
    adj[1] = {2};
    adj[2] = {1, 3};
    adj[3] = {2};
    adj[4] = {5};
    adj[5] = {4, 6};
    adj[6] = {5};
    adj[7] = {8};
    adj[8] = {7};
    solution s;
    cout<<s.countpreivences(adj,9);
    return 0;
}