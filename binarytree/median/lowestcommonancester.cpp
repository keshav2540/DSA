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
 node*lowestcommonanechester(node *root, node*l1,node*l2 ){
    if(root==nullptr ||root==l1||root==l2) return root;
    node*left=lowestcommonanechester(root->left,l1,l2);
    node*right=lowestcommonanechester(root->right,l1,l2);
    if(left==nullptr) return right;
    else if(right==nullptr) return left;
    else return root;
 }

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    node*temp=lowestcommonanechester(root,root->left, root->left->left);
    cout<<temp->val;
}