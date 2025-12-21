// this is apply for the dirested acycle graph sort according to can move
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], vector<int> &visit, stack<int> &st)
{
    visit[node] = 1;
    for (auto i : adj[node])
    {
        if (!visit[i])
        {
            dfs(i, adj, visit, st);
        }
    }
    st.push(node);
}
vector<int> toposort(vector<int> adj[], int v)
{
    stack<int> st;
    vector<int> visit(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visit[i])
        {
            dfs(i, adj, visit, st);
        } }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            cout << st.top() << " ";
            st.pop();
        }
    return ans;
}
int main()
{
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    toposort(adj, 6);
    return 0;
}