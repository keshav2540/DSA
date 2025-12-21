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
vector<int>inorder(node*root){
    vector<int>inorder;
    node*curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            inorder.push_back(curr->val);
            curr=curr->right;
        }
        else{
            node*prev=curr->left;
            while(prev->right && prev->right!=curr)
            {
                prev=prev->right;
            }
            if(prev->right==nullptr){
                prev->right=curr;
                curr=curr->left;
            }
            else{
                prev->right=nullptr;
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }
    } return inorder;

}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->right = new node(6);
    for(int i:inorder(root)) cout<<i<<" ";
}