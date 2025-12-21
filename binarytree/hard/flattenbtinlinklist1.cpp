#include <bits/stdc++.h> // try morrie treversal deep learning
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
// void flattern(node *root, node *&prev)
// {
//     if (!root)
//         return;
//     flattern(root->right, prev);
//      flattern(root->left, prev);
//     root->right = prev;
//     root->left = nullptr;
//     prev = root;
// }
 void flattern(node*&root,stack<node*>&st){
st.push(root);
while(!st.empty()){
 node* curr=st.top();st.pop();
 if(curr->right)st.push(curr->right);
 if(curr->left) st.push(curr->left);
 if(!st.empty()){
    curr->right=st.top();
    curr->left=nullptr;
 }
}
 }

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->right = new node(6);
    root->right->right->left = new node(7);
    node*prev=nullptr;
    stack<node*>st;
    flattern(root,st);
    cout << root->val;
    cout << root->right->val;
    cout << root->right->right->val;
    cout << root->right->right->right->val;
    cout << root->right->right->right->right->val;
    cout << root->right->right->right->right->right->val;
    cout << root->right->right->right->right->right->right->val;
}