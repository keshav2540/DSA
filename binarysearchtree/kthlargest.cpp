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
void inorder(node*root,int k,int &count){
    if(root==NULL) return ;
    inorder(root->right,k,count); 
     count++;
      if(count==k) {cout<<root->val; return;}
    // cout<<root->val<<" ";
    inorder(root->left,k,count);
    return ;
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
    int count=0;
    inorder(root,2,count);
}