#include <bits/stdc++.h>
using namespace std;
class disjointset
{
    vector<int> rank, parent, size;

public:
    disjointset(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findpar(parent[node]);
    }
    void unionbyrank(int u, int v)
    {
        int pv = findpar(v);
        int pu = findpar(u);
        if (pv == pu)
            return;
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionbysize(int u, int v)
    {
        int pv = findpar(v);
        int pu = findpar(u);
        if (pv == pu)
            return;
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
vector<int>numberofisland(int n,int m,vector<vector<int>>&operation){
    int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, 1, 0, -1};
   disjointset ds(n*m);
   vector<vector<int>>vis(n,vector<int>(m,0));
   int count=0;
   vector<int>ans;
   for(auto i:operation){
    int row=i[0];
    int col=i[1];
    if(vis[row][col]==1) {ans.push_back(count) ; continue;}
    vis[row][col]=1;
    count++;
    for(int j=0;j<4;j++){
        int nrow=row+drow[j];
        int ncol=col+dcol[j]; 
        if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&& vis[nrow][ncol]==1){
            int nodeid=row*m+col;
            int adjnodeid=nrow*m+ncol;
            if(ds.findpar(nodeid)!=ds.findpar(adjnodeid)){
                count--;
                ds.unionbysize(nodeid,adjnodeid);
            }
        }
    } ans.push_back(count);
   }for(auto it:ans)cout<<it<<" ";
   return ans;
}
int main()
{
    vector<vector<int>> adj = {{0, 0},
                               {0, 0},
                               {1,1},
                               {1, 0},
                               {0, 1},
                               {0, 3},
                               {1, 3},
                               {0, 4},
                               {3,2},
                               {2,2},
                               {1,2},
                               {0, 2}};
    numberofisland(4,5,adj);
}