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
bool checktreeidentical(node*tree1,node*tree2){
      if(tree1==nullptr||tree2==nullptr){
        return tree1==tree2;
      }
      return( tree1->val==tree2->val)&&checktreeidentical(tree1->left,tree2->left)&&checktreeidentical(tree1->right,tree2->right);
}

int main() {
    node*root1=new node(1);
    root1->left=new node(2);
    root1->right=new node(3);
    root1->left->left=new node(4);
    root1->left->right=new node(5);
    root1->right->left=new node(6);
    root1->right->right=new node(7);
     node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    // root->right->right=new node(7);
   cout<<checktreeidentical(root1,root);
    return 0;}