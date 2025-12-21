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
vector<vector<int>>verticaltraversal(node*root){
   vector<vector<int>>ans;           
    if(root==NULL) return ans;
   map<int,map<int,multiset<int>>>nodes;
   queue<pair<node*,pair<int,int>>>todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        node*temp=p.first;
        int x=p.second.first;
        int y=p.second.second;
        nodes[x][y].insert(temp->val);
        if(temp->left) todo.push({temp->left,{x-1,y+1}});
        if(temp->right) todo.push({temp->right,{x+1,y+1}});  
    }for(auto &p:nodes){
        vector<int>col;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }ans.push_back(col);
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
    vector<vector<int>>ans=verticaltraversal(root);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;}
    return 0;}