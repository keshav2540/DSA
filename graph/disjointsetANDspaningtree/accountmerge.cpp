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
vector<vector<string>>mergedetails(vector<vector<string>>details)
{ int n=details.size();
    disjointset ds(n);
    unordered_map<string,int>mapmail;
    for(int i=0;i<n;i++){
    for(int j=1;j<details[i].size();j++){
     string mail=details[i][j];
     if(mapmail.find(mail)==mapmail.end()){
        mapmail[mail]=i;
     }
     else{
        ds.unionbysize(i,mapmail[mail]);
     }
     }
    }
    vector<string>mergemails[n];
    for(auto it:mapmail){
        string mail=it.first;
        int node=ds.findpar(it.second);
        mergemails[node].push_back(mail);
    }
    vector<vector<string>>ans;
    for(int i=0;i<n;i++){
        if(mergemails[i].size()==0)continue;
        sort(mergemails[i].begin(),mergemails[i].end());
        vector<string>temp;
        temp.push_back(details[i][0]);
        for(auto it:mergemails[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    vector<vector<string>> details = {{"john","j1@.com","j2@.com","j3@.com"},
                               {"john","j4@.com"},
                               {"raj","r1@.com","r2@.com"},
                               {"john","j1@.com","j5@.com"},
                                {"raj","r2@.com","r4@.com"},
                               {"marry","m1@.com"}};
    for(auto &it:mergedetails(details)){
        for(auto i:it){
            cout<<i<<" -> ";
        }cout<<endl;
    }
}