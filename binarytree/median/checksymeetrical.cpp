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
bool check(node*left,node*right){
    if(left==nullptr||right==nullptr)return left==right;
    if(left->val!=right->val) return false;
    return check(left->left,right->right)&& check(left->right,right->left);
}
 bool symmetrical(node *root)
{
    return check(root->left,root->right);}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);
   cout<<symmetrical(root);
}