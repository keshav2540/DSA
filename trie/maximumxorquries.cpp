#include <bits/stdc++.h>
using namespace std;
struct node
{
public:
    node *bit[2]={nullptr};
    bool containkey(int key){
        return (bit[key]!=nullptr);
    }
    node*get(int key){
        return bit[key];
    }
    void put(int key,node*nod){
        bit[key]=nod;
    }
};
class trie{
    public:
    node*root;
    trie(){
        root=new node();
    }
    void insert(int num){
        node*temp=root;
        for(int i=31;i>=0;i--){
            int bits=(num>>i)&1;
            if(!temp->containkey(bits)){
                temp->put(bits,new node());
            }
        temp=temp->get(bits);
        }
    }
      public :
       int getmax(int num){
        node*temp=root;
        int maxnum=0;
         for(int i=31;i>=0;i--){
            int bits=(num>>i)&1;
            if(temp->containkey(1-bits)){
                maxnum=maxnum|(1<<i);
                temp=temp->get(1-bits);
            }
            else{
                  temp=temp->get(bits); 
            }
         } return maxnum;
       }

     vector<int> maxxorquries(vector<int>&arr,vector<vector<int>>&qu){
        sort(arr.begin(),arr.end());
        vector<pair<int,pair<int,int>>>qq;
        int q=qu.size();
        for(int i=0;i<q;i++){
            qq.push_back({qu[i][1],{qu[i][0],i}});
        }
        sort(qq.begin(),qq.end());
        vector<int>ans(q);
        int ind=0;
        int n=arr.size();
        trie t;
        for(int i=0;i<q;i++){
            int ai=qq[i].first;
            int xi=qq[i].second.first;
            int qind=qq[i].second.second;
            while(ind<n && arr[ind]<=ai){
                t.insert(arr[ind]);
                ind++;
            }
            if(ind==0)ans[qind]=-1;
            else ans[qind]=t.getmax(xi);
        } return ans;

     }
    };
int main() {
    vector<int>arr={1,3,2,5,4};
    vector<vector<int>>quires={{3,4},{5,2},{2,5},{3,1}};
    trie t;
    for(int i:t.maxxorquries(arr,quires)) cout<<i<<" ";

    return 0;
}