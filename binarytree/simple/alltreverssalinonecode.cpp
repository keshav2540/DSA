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
vector<vector<int>>all(node*root){
   vector<vector<int>>ans(3);           
    if(root==NULL) return ans;
    stack<pair<node*,int>>st;
    st.push({root,1});
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            ans[0].push_back(it.first->val);
            it.second++;
            st.push(it);
           if(it.first->left) st.push({it.first->left,1}); 
        }
        else if(it.second==2){
            ans[1].push_back(it.first->val);
             it.second++;
             st.push(it);
           if(it.first->right) st.push({it.first->right,1}); 
        }
        else{
            ans[2].push_back(it.first->val);
        }
        } 
    return ans;}
int main() {
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    vector<vector<int>>ans=all(root);
    cout<<"preorder: ";
    for(auto i:ans[0]) cout<<i<<" ";
    cout<<endl;
    cout<<"inorder: ";
    for(auto i:ans[1]) cout<<i<<" ";
    cout<<endl;
    cout<<"postorder: ";
    for(auto i:ans[2]) cout<<i<<" ";
    cout<<endl;
    return 0;
}