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
 bool path(node *root, vector<int> &ans,node*target)
{
    if (!root) return 0;
    ans.push_back(root->val);
    if(root==target) return true;
    if(path(root->left,ans,target)||path(root->right,ans,target)) return true;
    ans.pop_back();
    return false;
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
    vector<int>ans;
    path(root,ans,root->right->right);
    for (int i : ans)
        cout << i << ' ';
}