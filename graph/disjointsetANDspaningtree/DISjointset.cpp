/* it preform task in constatn time complexity around o(4alpa)*/
#include <bits/stdc++.h>
using namespace std;
class disjointset{
    vector<int>rank,parent,size;
    public:
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findpar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int pv=findpar(v);
        int pu=findpar(u);
        if(pv==pu)return ;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv]){
           parent[pv]=pu;
        }
        else {
              parent[pv]=pu;
              rank[pu]++;
        }
    }
    void unionbysize(int u,int v){
          int pv=findpar(v);
        int pu=findpar(u);
        if(pv==pu)return ;
         if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else {
              parent[pv]=pu;
              size[pu]+=size[pv];
        }

    }
};
int main() {
      disjointset ds(7);
      ds.unionbysize(1,2);
      ds.unionbysize(2,3);
      ds.unionbysize(4,5);
      ds.unionbysize(6,7);
      ds.unionbysize(5,6);
      if(ds.findpar(3)==ds.findpar(7))cout<<"same"<<endl;
      else cout<<" not same"<<endl;
      ds.unionbysize(3,7);
       if(ds.findpar(3)==ds.findpar(7))cout<<"same"<<endl;
      else cout<<" not same"<<endl;
    return 0;
}