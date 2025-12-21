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
vector<vector<int>>zig_zag(node*root){
   vector<vector<int>>ans;           
    if(root==NULL) return ans;
    queue<node*>q;
    q.push(root);
    bool lefttoright=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>row(size);
        for(int i=0;i<size;i++){
         node*temp=q.front();
         q.pop();
         int index=lefttoright? i:size-i-1;
         row[index]=temp->val;
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
            }
        lefttoright=!lefttoright;
             ans.push_back(row);
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
    vector<vector<int>>ans=zig_zag(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;}
    return 0;}