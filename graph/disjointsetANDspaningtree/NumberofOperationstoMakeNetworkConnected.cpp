#include <bits/stdc++.h>// remove one node and add an0ther node
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
int connetingGarphpath(vector<vector<int>>edges, int v)
{
    disjointset ds(v);
    int countextraedges=0;
   for(auto it:edges){
    int u=it[0];
    int v=it[1];
    if(ds.findpar(u)==ds.findpar(v)){
        countextraedges++;
    }
    else ds.unionbysize(u,v);
   }
    int count = -1; //want n-1
    for (int i = 0; i < v; i++)
    { 
        if (i == ds.findpar(i)){
            count++;}
    }
    return count<=countextraedges?count:-1;
}
int main()
{
    vector<vector<int>> adj = {{0, 3},
                               {0, 1},
                               {0, 2},
                               {1,2},
                               {2,3},
                               {4,5},
                               {5,6},{7,8}};
    cout << connetingGarphpath(adj, 8);
}