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
class solution
{
    node *first;
    node *prev;
    node *middle;
    node *last;
    void inorder(node *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        if (prev != nullptr && root->val < prev->val)
        {
            if (first == nullptr)
            {
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recovertree(node *&root)
    {
        first = middle = last = nullptr;
        prev = new node(INT_MIN);
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
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
    node *root = new node(1);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->left->left = new node(9);
    root->left->left->right = new node(3);
    root->left->left->right->right = new node(4);
    root->left->right = new node(7);
    root->left->right->left = new node(6);
    root->left->right->right = new node(8);
    root->right = new node(12);
    root->right->left = new node(10);
    root->right->right = new node(13);
    solution s;
    s.recovertree(root);
    inorder(root);
}