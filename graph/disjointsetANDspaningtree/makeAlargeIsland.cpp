// we can change any one 0 to 1
//return sizeof island
#include <bits/stdc++.h>
using namespace std;
class disjointset
{public:
    vector<int> rank, parent, size;
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
int maxconnection(vector<vector<int>>&grid){
    int m=grid[0].size();
    int n=grid.size();
     int drow[] = {-1, 0, 1, 0};
     int dcol[] = {0, 1, 0, -1};
    disjointset ds(n*m);
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<m;col++){
         if(grid[row][col]==0)continue;
        for(int j=0;j<4;j++){
        int nrow=row+drow[j];
        int ncol=col+dcol[j]; 
        if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&& grid[nrow][ncol]==1){
            int nodeid=row*m+col;
            int adjnodeid=nrow*m+ncol; 
            ds.unionbysize(nodeid,adjnodeid);
        }
    }
}
}
 int mx=0;
   for(int row=0;row<n;row++){
    for(int col=0;col<m;col++){
        if(grid[row][col]==1)continue;
        set<int>component;
        for(int i=0;i<4;i++){
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m) {
            if(grid[nrow][ncol]==1){
                component.insert(ds.findpar(nrow*m+ncol));
            }
        } 
    }
    int sizetotal=0;
    for(auto it: component){
        sizetotal+=ds.size[it];
    }
        mx=max(mx,sizetotal+1);
  }
}
for(int i = 0; i < n*m; i++){
    mx = max(mx, ds.size[ds.findpar(i)]);
}
 return mx;
}
int main() {
    vector<vector<int>>grid={{1,1,0,1,1},
                             {1,1,0,1,1},
                             {1,1,0,1,1},
                             {0,0,1,0,0},
                             {0,0,1,1,1},
                             {0,0,1,1,1},
};
cout<<maxconnection(grid);
    return 0;
}