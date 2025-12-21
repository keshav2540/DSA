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
vector<int>inorder(node*root){
    vector<int>ans; 
    stack<node*>st;
    node*node=root;
    while(true)
    {
        if(node!=NULL){
        st.push(node);
        node=node->left;
    }
    else{
        if(st.empty()) break;
        node=st.top();
        st.pop();
        ans.push_back(node->val);
        node=node->right;
    }}return ans;
   }
int main() {
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->left->right=new node(8);
    root->right->right=new node(7);
    for(int i:inorder(root)) cout<<i<<" ";
    return 0;
}