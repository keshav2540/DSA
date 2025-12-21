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
bool isleaf(node*root){
    return !(root->left||root ->right);
}
void addleftboundry(node*root,vector<int>&ans){
    node*curr=root->left;
    while(curr){
        if(!isleaf(curr))ans.push_back(curr->val);
       if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}
void addleaves(node*root,vector<int>&ans){
    if(isleaf(root)){
        ans.push_back(root->val);
    }
    if(root->left) addleaves(root->left,ans);
    if(root->right) addleaves(root->right,ans);
}
void addrightboundry(node*root,vector<int>&ans){
    node*curr=root->right;
    vector<int>tmp;
    while(curr){
        if(!isleaf(curr))ans.push_back(curr->val);
       if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=tmp.size()-1;i>=0;i--){
        ans.push_back(tmp[i]);    }

    }

vector<int>printboundry(node*root){
   vector<int>ans;           
    if(root==NULL) return ans;
    if(!isleaf(root)) ans.push_back(root->val);
    addleftboundry(root,ans);
    addleaves(root,ans);
    addrightboundry(root,ans);
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
    for(int i:printboundry(root)) cout<<i<<" ";   }