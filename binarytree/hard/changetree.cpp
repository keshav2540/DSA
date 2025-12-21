//change trree nodes according to child sum
#include <bits/stdc++.h>
using namespace std;
template <typename t>
class node
{
public:
    t val;
    node *left;
    node *right;
    node(t a)
    {
        val = a;
        left = nullptr;
        right = nullptr;
    }
};
void change(node<int>*root){
    if(root==nullptr )return ;
    int child=0;
    if(root->left){
        child+=root->left->val;
    }
    if(root->right){
        child+=root->right->val;
    }
    if(child>=root->val) root->val=child;
    else {  
          if (root->left) root->left->val = root->val;
        if (root->right) root->right->val = root->val;
    }
    change(root->left);
    change(root->right);
     int tot=0;
     if(root->left!=nullptr)tot+=root->left->val;
     if(root->right!=nullptr)tot+=root->right->val;
     if(root->left!=nullptr || root->right!=nullptr)root->val=tot;
     return;
}

int main()
{
    node<int> *root = new node<int>(1);
    root->left = new node<int>(2);
    root->right = new node<int>(3);
    root->left->left = new node<int>(4);
    root->left->left->left = new node<int>(8);
    root->left->right = new node<int>(5);
    root->right->left = new node<int>(6);
    root->right->right = new node<int>(7);
    root->right->right->right = new node<int>(9);
    vector<int> ans;
     change(root);
     cout<<root->val<<endl;
    cout<<root->left->val<<endl;
    cout<<root->right->val<<endl;
    cout<<root->left->left->val<<endl;
    cout<<root->left->left->left->val<<endl;
    cout<<root->left->right->val<<endl;
    cout<<root->right->left->val<<endl;
   cout<< root->right->right->val<<endl;
    cout<<root->right->right->right->val<<endl;
}