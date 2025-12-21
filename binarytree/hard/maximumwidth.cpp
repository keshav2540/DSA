// width is maximum distance betweeen teo nodes
#include <bits/stdc++.h>
using namespace std;
template <typename t>
class node
{
public:
    t val;
    node *left;
    node *right;
    node(t a)
    {
        val = a;
        left = nullptr;
        right = nullptr;
    }
};
int width(node<int>*root){
    if(!root) return 0;
    int ans=0;
    queue<pair<node<int>*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int mini=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int curr_id=q.front().second-mini;
            node<int>*temp=q.front().first;
            q.pop();
            if(i==0) first=curr_id;
            if(i==size-1) last=curr_id;
            if(temp->left){
                q.push({temp->left,curr_id*2+1});
            }
            if(temp->right){
                q.push({temp->right,curr_id*2+2});
            }
        } ans=max(ans,last-first+1);
    } return ans;
}

int main()
{
    node<int> *root = new node<int>(1);
    root->left = new node<int>(2);
    root->right = new node<int>(3);
    root->left->left = new node<int>(4);
    root->left->left->left = new node<int>(8);
    root->left->right = new node<int>(5);
    root->right->left = new node<int>(6);
    root->right->right = new node<int>(7);
    root->right->right->right = new node<int>(9);
    vector<int> ans;
     cout<<width(root);
}