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
class nodeval{
     public:
    int maxnode,minnode,maxsize;
    nodeval(int minnode,int maxnode,int maxsize){
        this ->minnode=minnode;
        this->maxnode=maxnode;
        this->maxsize=maxsize;
    }
};
class solution
{ nodeval largestbstsubtreehelper(node*root){
        if(!root) return nodeval(INT32_MAX,INT32_MIN,0);
        auto left=largestbstsubtreehelper(root->left);
        auto right=largestbstsubtreehelper(root->right);
        if(left.maxnode<root->val&&root->val<right.minnode){
            // it is bst
            return nodeval(min(root->val,left.minnode),max(root->val,right.maxnode),left.maxsize+right.maxsize+1);
        } return nodeval(INT32_MAX,INT32_MIN,max(left.maxsize,right.maxsize));
        }
     public:
     int largestbstsubtree(node*root){
        return largestbstsubtreehelper(root).maxsize;
     }   
};
void inorder(node*root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main()
{
    node *root = new node(9);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->left->left = new node(1);
    root->left->left->right = new node(3);
    root->left->left->right->right = new node(4);
    root->left->right = new node(7);
    root->left->right->left = new node(6);
    root->left->right->right = new node(8);
    root->right = new node(12);
    root->right->left = new node(10);
    root->right->right = new node(13);
    solution s;
    cout<<s.largestbstsubtree(root);
}