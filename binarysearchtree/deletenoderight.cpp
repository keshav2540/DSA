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
node*findlastleft(node*root){
    if(!root->left) return root;
    return findlastleft(root->left);
}
node*helper(node*root){
    if(!root->left)return root->right;
else if(!root->right) return root->left;
   node*leftchild=root->left;
    node*lastleft=findlastleft(root->right);
    lastleft->left=leftchild;
    return root->right;
}
void inorder(node*root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
node* deletenode(node*root,int key){ // child right take position
    if(root==nullptr)return nullptr;
    if(root->val==key){
        return helper(root);
    }
    node*dummy=root;
    while(root){
        if(root->val>key){
            if(root->left && root->left->val==key){
                root->left=helper(root->left);
                break;
            }
            else root=root->left;
        }
        else{
            if(root->right && root->right->val==key){
                root->right=helper(root->right);
                break;
            }
            else root=root->right;
        }
    }  return dummy;}


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
    inorder(deletenode(root,7));
}