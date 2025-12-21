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
vector<int>preorder(node*root){
    vector<int>ans;
    if(root==NULL) return ans;
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        ans.push_back(root->val);
        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
    }return ans;
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
    for(int i:preorder(root)) cout<<i<<" ";
    return 0;
}