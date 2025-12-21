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
 void leftveiw(node *root, int level, vector<int> &ans)
{
    if (root == nullptr)
        return ;
    if (level == ans.size())
        ans.push_back(root->val);
    if (root->right)
        leftveiw(root->right, level + 1, ans);
    if (root->left)
        leftveiw(root->left, level + 1, ans);
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
    leftveiw(root,0,ans);
    for (int i : ans)
        cout << i << ' ';
}