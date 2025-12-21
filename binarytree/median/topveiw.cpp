#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node*left;
    node*right;
    node(int a){
        val=a;
        left=nullptr;
        right=nullptr;
    }
};
vector<int>topveiw(node*root){
    vector<int>ans;
    if(root==nullptr) return ans;
    map<int,int>mpp;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        node*temp=it.first;
        int line=it.second;
        if(mpp.find(line)==mpp.end()) mpp[line]=temp->val;
        if(temp->left) q.push({temp->left,line-1});
        if(temp->right) q.push({temp->right,line+1});}
        for(auto it:mpp){
            ans.push_back(it.second);
        }
     return ans;
    }
   
int main() {
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    for(int i:topveiw(root)) cout<<i<<' ';}