#include <bits/stdc++.h>
using namespace std;
void dfs(int &st, vector<int> adj[], vector<int> &visit, vector<int> &ans)
{
    visit[st] = true;
    ans.push_back(st);
    for (auto i : adj[st])
    {
        if (!visit[i])
        {
            dfs(i, adj, visit, ans);
        }
    }
}
vector<int> ansi(int v, vector<int> adj[])
{
    vector<int> visit(v + 1, false);
    int st = 1;
    vector<int> ans;
    dfs(st, adj, visit, ans);
    return ans;
}

int main()
{
    vector<int> adj[9];
    adj[0] = {};
    adj[1] = {2, 6};
    adj[2] = {1, 3, 4};
    adj[3] = {2};
    adj[4] = {2, 5};
    adj[5] = {4, 7};
    adj[6] = {1, 7, 8};
    adj[7] = {5, 6};
    adj[8] = {6};
    vector<int> ans = ansi(8,adj);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}