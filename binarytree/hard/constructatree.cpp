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
node*build(vector<int>&preorder,int prest,int preend,vector<int>&inorder,int inst,int inend,map<int,int>&mpp){
    if(prest>preend||inst>inend) return nullptr;
    node*root=new node(preorder[prest]);
    int inroot=mpp[root->val];
    int numsleft=inroot-inst;
    root->left=build(preorder,prest+1,prest+numsleft,inorder,inst,inroot-1,mpp);
    root->right=build(preorder,prest+numsleft+1,preend,inorder,inroot+1,inend,mpp);
      return root;
}
node*bulidtree(vector<int>preorder,vector<int>inorder){
    map<int,int>mpp;
    for(int i=0;i<inorder.size();i++){
        mpp[inorder[i]]=i;
    }
    node*root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    return root;
}
int main() {
    vector<int>preorder={10,20,40,50,30,60};
    vector<int>inorder={40,20,50,10,60,30};
    node*root=bulidtree(preorder,inorder);
    cout<<root->val<<endl;
    cout<<root->left->val<<endl;
    cout<<root->right->val<<endl;
    cout<<root->left->left->val<<endl;
    cout<<root->left->right->val<<endl;
    cout<<root->right->left->val<<endl;
    return 0;
}