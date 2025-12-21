#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
    node(int a)
    {
        val = a;
        left = nullptr;
        right = nullptr;
    }
};
node*lowestcommonanchester(node*root,node*p,node*q){
    if(!root)return nullptr;
    int curr=root->val;
    if(curr<p->val &&curr<q->val){
        return lowestcommonanchester(root->right,p,q);
    }
    if(curr>p->val &&curr>q->val){
        return lowestcommonanchester(root->right,p,q);
} return root;
}


int main()
{
    node *root = new node(9);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->left->left = new node(1);
    root->left->left->right = new node(3);
    root->left->left->right->right= new node(4);
    root->left->right = new node(7);
    root->left->right->left= new node(6);
    root->left->right->right= new node(8);
    root->right = new node(12);
    root->right->left = new node(10);
    root->right->right= new node(13);
    cout<<lowestcommonanchester(root,root->left->left->right, root->left->left->left)->val;
}