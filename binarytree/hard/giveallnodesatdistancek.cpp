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
void markparent(node<int>*root,unordered_map<node<int>*,node<int>*>&parenttrack,node<int>*target){
    queue<node<int>*>q;
    q.push(root);
    while(!q.empty()){
        node<int>*curr=q.front();
        q.pop();
        if(curr->left){
            parenttrack[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            parenttrack[curr->right]=curr;
            q.push(curr->right);
        }
    }
}
vector<int>distancek(node<int>*root,node<int>*target,int k){
    unordered_map<node<int>*,node<int>*>parenttrack;
     markparent(root,parenttrack,target);
     unordered_map<node<int>*,bool>visit;
     queue<node<int>*>qw;
     qw.push(target);
     visit[target]=true;
     int curr_level=0;
     while(!qw.empty()){
        int size=qw.size();
        if(curr_level++==k)break;
        for(int i=0;i<size;i++){
            node<int>*curr=qw.front();
            qw.pop();
            if(curr->left&& !visit[curr->left]){
                qw.push(curr->left);
                visit[curr->left]=true;
            }
            if(curr->right&& !visit[curr->right]){
                qw.push(curr->right);
                visit[curr->right]=true;
            }
            if(parenttrack[curr]&& !visit[parenttrack[curr]]){
                qw.push(parenttrack[curr]);
                visit[parenttrack[curr]]=true;
            }
        }
     }
     vector<int>result;
     while(!qw.empty()){
        result.push_back(qw.front()->val);
        qw.pop();
     }
      return result;
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
    vector<int>ans=distancek(root, root->left,2);
    for(auto i:ans) cout<<i<<" ";
}