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
node*insertnode(node*&root,int key){
 if(!root) return new node(key);
 node*temp=root;
 while(temp){
    if(temp->val>=key){
        if(temp->left){
            temp=temp->left;
        }
        else{
            temp->left=new node(key);
           break;
        }
    }
    else{ 
        if(temp->right){
            temp=temp->right;
        }
        else{
            temp->right=new node(key);
           break;
        }}
 } return root;}

int main()
{
    node *root = new node(8);
    root->left = new node(5);
    root->right = new node(12);
    root->left->left = new node(4);
    root->left->right = new node(7);
    root->left->right->left = new node(6);
    root->right->left = new node(10);
    root->right->right = new node(14);
    root->right->right->left = new node(13);
    insertnode(root,0)->val;
    cout<<root->left->left->left->val;
}