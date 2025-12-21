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
vector<int>postorder(node*root){
    vector<int>ans;
    stack<node*>st1;
    stack<node*>st2;
    st1.push(root);
    while(!st1.empty()){
        st2.push(st1.top());
        root=st1.top();st1.pop();
        if(root->left) st1.push(root->left);
        if(root->right) st1.push(root->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->val);
        st2.pop();
    } return ans;
}

int main() {
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    for (auto i:postorder(root))cout<<i<<" ";
    return 0;
}