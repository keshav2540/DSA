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
node*build(vector<int>&postorder,int postst,int postend,vector<int>&inorder,int inst,int inend,map<int,int>&mpp){
    if(postst>postend||inst>inend) return nullptr;
    node*root=new node(postorder[postend]);
    int inroot=mpp[root->val];
    int numsleft=inroot-inst;
    root->left=build(postorder,postst,postst+numsleft-1,inorder,inst,inroot-1,mpp);
    root->right=build(postorder,postst+numsleft,postend-1,inorder,inroot+1,inend,mpp);
      return root;
}
node*bulidtree(vector<int>postorder,vector<int>inorder){
    map<int,int>mpp;
    for(int i=0;i<inorder.size();i++){
        mpp[inorder[i]]=i;
    }
    node*root=build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
    return root;
}
int main() {
    vector<int>postorder={40,50,20,60,30,10};
    vector<int>inorder={40,20,50,10,60,30};
    node*root=bulidtree(postorder,inorder);
    cout<<root->val<<endl;
    cout<<root->left->val<<endl;
    cout<<root->right->val<<endl;
    cout<<root->left->left->val<<endl;
    cout<<root->left->right->val<<endl;
    cout<<root->right->left->val<<endl;
    return 0;
}