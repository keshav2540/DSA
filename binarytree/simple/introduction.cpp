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
/*travel type
1.DFS
inorder(l,root,r)
preorder(root,l,r)
postorder(l,r,root)
2.BFS
level order treversal*/

int main() {
    node*root=new node(1);
    root->left->val=2;
    root->right->val=3;
    root->left->left->val=4;
    root->left->right->val=5;
    root->right->left->val=6;
    root->right->right->val=7;
    return 0;
}