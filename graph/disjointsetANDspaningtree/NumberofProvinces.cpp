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
int numberofprovinces(vector<vector<int>> adj, int v)
{
    disjointset ds(v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (adj[i][j] == 1)
                ds.unionbysize(i, j);
        }
    }
    int count = 0;
    for (int i = 0; i < v; i++)
    { 
        if (i == ds.findpar(i)){cout<<i<<endl;
            count++;}
    }
    return count;
}
int main()
{
    vector<vector<int>> adj = {{0, 0, 1, 0, 0, 0, 0, 0},
                               {0, 1, 0, 1, 0, 0, 0, 0},
                               {0, 0, 1, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 1, 0, 0},
                               {0, 0, 0, 0, 1, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 1},
                               {0, 0, 0, 0, 0, 0, 1, 0}};
    cout << numberofprovinces(adj, 8);
}