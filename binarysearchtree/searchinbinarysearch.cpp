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
node*binarysearch(node*root,int key){
    if(!root||root->val==key)return root;
 return root->val>key?binarysearch(root->left,key):binarysearch(root->right,key);
}

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
    cout<<binarysearch(root,6)->val;
}