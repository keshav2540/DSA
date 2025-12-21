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
void levelorder1(node*root){
    queue<node*>q;
    q.push(root);
    while(q.size()>0){
        node*curr=q.front();
        q.pop();
        cout<<curr->val<<" ";
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
}
void levelorder2(node*root){
    queue<node*>q;
    q.push(root);
    q.push(nullptr);
    while(q.size()>0){
        node*curr=q.front();
        q.pop();
        if(curr==nullptr){
        if(!q.empty()){cout<<endl;
         q.push(nullptr);}
         else break;}
        else
        {cout<<curr->val<<" ";
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }}
    }
}
vector<vector<int>>levelorder3(node*root){
    vector<vector<int>>ans;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
      int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            node*curr=q.front();
            q.pop();
            level.push_back(curr->val);
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }}
        ans.push_back(level);
        }
return ans;
    }
int main() {
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->left->right=new node(6);
    root->right->right=new node(7);
    vector<vector<int>>levelorder=levelorder3(root);
    for(int i=0;i<levelorder.size();i++){
        for(int j=0;j<levelorder[i].size();j++){
            cout<<levelorder[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}