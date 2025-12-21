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
void preorderprint(node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorderprint(root->left);
    preorderprint(root->right);
}
//  we have inorder preoder ko sort karne pqr mil jaega
// using upper bound concept;
node *build(vector<int> preorder, int &i, int bound)
{
    if (preorder.size() == i || preorder[i] > bound)
        return nullptr;
    node *root = new node(preorder[i++]);
    root->left = build(preorder, i, root->val);
    root->right = build(preorder, i, bound);
    return root;
}
node *buildpreorder(vector<int> &preorder)
{
    int i = 0;
    return build(preorder, i, INT_MAX);
}

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    preorderprint(buildpreorder(preorder));
}