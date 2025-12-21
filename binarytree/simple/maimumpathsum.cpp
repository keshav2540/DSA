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
 int pathsum(node*root,int &maxi){
 if(root==nullptr)return 0;
 int lh=pathsum(root->left,maxi);
 int rh=pathsum(root->right,maxi);
 maxi=max(maxi,lh+rh+root->val);
 return root->val+max(rh,lh);
 }

int main() {
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    int ans=INT32_MIN;
    pathsum(root,ans);
     cout<<ans;
    
}